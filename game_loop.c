/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:54:44 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/05 19:37:34 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// レイキャスティング用の構造体を初期化します。
static void	_init_rc(t_raycasting *rc, t_data *data)
{
	rc->ceiling_color = data->ceiling_color;
	rc->floor_color = data->floor_color;
	rc->map = data->map;
	rc->texture_n = data->textures.north;
	rc->texture_e = data->textures.east;
	rc->texture_w = data->textures.west;
	rc->texture_s = data->textures.south;
}

// レイキャスティングを行った上でバッファをウィンドウに表示
int draw_buffer(t_cublx *cublx)
{
	t_data			*data;
	t_raycasting	rc;
	int				i;

	data = cublx->user->param;
	_init_rc(&rc, data);
	i = 0;
	while (i < WIDTH)
	{
		rc.draw_pos.x = i++;
		cublx->raycasting(cublx, data->player.camera, rc);
	}
}

// 1フレームごとに実行されるループ関数
int	game_loop(t_cublx *cublx)
{
	t_data		*data;
	t_camera	*cam;
	double		rot_spd;
	double		mv_spd;

	data = cublx->user->param;
	cam = data->player.camera;
	rot_spd = data->player.rot_speed;
	mv_spd = data->player.move_speed;
	if (cublx->btn(cublx, XK_Left))
		cam->rotate(cam, -rot_spd);
	if (cublx->btn(cublx, XK_Right))
		cam->rotate(cam, rot_spd);
	if (cublx->btn(cublx, XK_w))
		cam->move(cam, cublx_vec2(0, -mv_spd), data->map, 0.25);
	if (cublx->btn(cublx, XK_s))
		cam->move(cam, cublx_vec2(0, mv_spd), data->map, 0.25);
	if (cublx->btn(cublx, XK_a))
		cam->move(cam, cublx_vec2(-mv_spd, 0), data->map, 0.25);
	if (cublx->btn(cublx, XK_d))
		cam->move(cam, cublx_vec2(mv_spd, 0), data->map, 0.25);
	if (cublx->btnp(cublx, XK_Escape))
		cublx->quit(cublx, EXIT_SUCCESS);
	return (0);
}
