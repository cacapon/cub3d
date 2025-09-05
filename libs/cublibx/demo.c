/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 07:00:21 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/05 18:02:55 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"
#include "demo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initial values are tentative for demonstration purposes.
static t_data	*init_data(void)
{
	t_data	*data;
	t_vec2	p_pos;
	t_vec2	p_dir;

	data = cublx_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	p_pos = (t_vec2){2.5, 2.5};
	p_dir = (t_vec2){0.0, -1.0};
	data->ceiling_color = 16711680;
	data->floor_color = 255;
	data->player = cublx_camera_new(p_pos, p_dir, 66.0);
	if (!data->player)
		return (free(data), NULL);
	data->textures.north = cublx_calloc(1, sizeof(t_img));
	data->textures.east = cublx_calloc(1, sizeof(t_img));
	data->textures.west = cublx_calloc(1, sizeof(t_img));
	data->textures.south = cublx_calloc(1, sizeof(t_img));
	data->map = cublx_calloc(5, sizeof(char *));
	data->map[0] = strdup("11111");
	data->map[1] = strdup("10001");
	data->map[2] = strdup("10N01");
	data->map[3] = strdup("10001");
	data->map[4] = strdup("11111");
	return (data);
}

/**
 * @brief Destructor for erasing user-defined dynamic allocation data.
 *
 * @param cublx
 * @return int
 */
static int	dest(t_cublx *cublx)
{
	int		i;
	t_data	*data;

	data = cublx->user->param;
	cublx_camera_del(&data->player);
	i = 0;
	while (i < 5)
	{
		if (data->map[i])
			free(data->map[i]);
		i++;
	}
	if (data->textures.north && data->textures.north->img)
		cublx->free_tex(cublx, &data->textures.north);
	if (data->textures.east && data->textures.east->img)
		cublx->free_tex(cublx, &data->textures.east);
	if (data->textures.west && data->textures.west->img)
		cublx->free_tex(cublx, &data->textures.west);
	if (data->textures.south && data->textures.south->img)
		cublx->free_tex(cublx, &data->textures.south);
	free(data->map);
	free(data);
	return (0);
}

static int	draw(t_cublx *cublx)
{
	int				i;
	t_data			*data;
	t_raycasting	rc;

	data = cublx->user->param;
	rc.ceiling_color = data->ceiling_color;
	rc.texture_n = data->textures.north;
	rc.texture_e = data->textures.east;
	rc.texture_w = data->textures.west;
	rc.texture_s = data->textures.south;
	rc.floor_color = data->floor_color;
	rc.map = data->map;
	i = 0;
	while (i < cublx->win_size.x)
	{
		rc.draw_pos.x = i++;
		cublx->raycasting(cublx, data->player, rc);
	}
	return (0);
}

static int	update(t_cublx *cublx)
{
	t_data				*data;
	double				speed;
	char				**map;
	static const double	margin = 0.25;

	data = cublx->user->param;
	map = data->map;
	speed = 0.03;
	if (cublx->btnp(cublx, XK_q))
		cublx->quit(cublx, EXIT_SUCCESS);
	if (cublx->btn(cublx, XK_w))
		data->player->move(data->player, cublx_vec2(0, -speed), map, margin);
	if (cublx->btn(cublx, XK_s))
		data->player->move(data->player, cublx_vec2(0, speed), map, margin);
	if (cublx->btn(cublx, XK_a))
		data->player->move(data->player, cublx_vec2(-speed, 0), map, margin);
	if (cublx->btn(cublx, XK_d))
		data->player->move(data->player, cublx_vec2(speed, 0), map, margin);
	if (cublx->btn(cublx, XK_Left))
		data->player->rotate(data->player, -speed);
	if (cublx->btn(cublx, XK_Right))
		data->player->rotate(data->player, speed);
	return (0);
}

int	main(void)
{
	t_cublx	*cublx;
	t_data	*param;

	param = init_data();
	cublx = cublx_new(1048, 768, "test");
	cublx_set_hooks(cublx, update, draw, dest);
	cublx->load_xpm(cublx, param->textures.north, "textures/north.xpm");
	cublx->load_xpm(cublx, param->textures.south, "textures/south.xpm");
	cublx->load_xpm(cublx, param->textures.west, "textures/west.xpm");
	cublx->load_xpm(cublx, param->textures.east, "textures/east.xpm");
	cublx_set_user_param(cublx, param);
	cublx_run(cublx);
	cublx_del(&cublx);
	return (0);
}
