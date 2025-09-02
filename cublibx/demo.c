/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 07:00:21 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/02 13:55:54 by ttsubo           ###   ########.fr       */
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
	p_pos = (t_vec2){2.5, 4.5};
	p_dir = (t_vec2){0.0, -1.0};
	data->ceiling_color = 16711680;
	data->floor_color = 255;
	data->player = cublx_camera_new(p_pos, p_dir, 66.0);
	if (!data->player)
		return (free(data), NULL);
	data->map = cublx_calloc(7 , sizeof(char *));
	data->map[0] = strdup("11111");
	data->map[1] = strdup("10001");
	data->map[2] = strdup("10201");
	data->map[3] = strdup("10001");
	data->map[4] = strdup("10N01");
	data->map[5] = strdup("10001");
	data->map[6] = strdup("11111");
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
	int		j;
	t_data	*data;

	data = cublx->user->param;
	cublx_camera_del(&data->player);
	i = 0;
	j = 0;
	while (i < 7)
	{
		if (!data->map[i])
			free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data);
	return (0);
}

static int	draw(t_cublx *cublx)
{
	int	i;
	t_data			*data;
	t_raycasting	rc;

	data = cublx->user->param;
	rc.ceiling_color = data->ceiling_color;
	rc.wall_color = 0xFFFFFF;
	rc.floor_color = data->floor_color;
	rc.map = data->map;
	i = 0;
	while (i < cublx->win_size.x)
	{
		rc.x = i++;
		cublx->raycasting(cublx, data->player, rc);
	}
	return (0);
}

static int	update(t_cublx *cublx)
{
	t_data	*data;
	double	speed;

	data = cublx->user->param;
	speed = 0.01;
	if (cublx->btnp(cublx, XK_q))
	{
		printf("push q btn\n");
		cublx_del(&cublx);
		exit(0);
	}
	if (cublx->btn(cublx, XK_w))
		data->player->move(data->player, cublx_vec2(0, -speed));
	if (cublx->btn(cublx, XK_s))
		data->player->move(data->player, cublx_vec2(0, speed));
	if (cublx->btn(cublx, XK_a))
		data->player->move(data->player, cublx_vec2(-speed, 0));
	if (cublx->btn(cublx, XK_d))
		data->player->move(data->player, cublx_vec2(speed, 0));
	if (cublx->btn(cublx, XK_Left))
		data->player->rotate(data->player, speed);
	if (cublx->btn(cublx, XK_Right))
		data->player->rotate(data->player, -speed);
	return (0);
}

int	main(void)
{
	t_cublx	*cublx;
	t_data	*param;

	param = init_data();
	cublx = cublx_new(500, 400, "test");
	cublx_set_hooks(cublx, update, draw, dest);
	cublx_set_user_param(cublx, param);
	cublx_run(cublx);
	cublx_del(&cublx);
	return (0);
}
