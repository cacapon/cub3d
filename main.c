/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:30:12 by yookamot          #+#    #+#             */
/*   Updated: 2025/08/25 18:07:24 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int dest(t_cublx *cublx)
{
	return (0);
}

int draw(t_cublx *cublx)
{
	t_data	*data;

	data = cublx->user->param;
	draw_buffer(cublx);
	display_player_position(data, cublx);
	return (0);
}

int update(t_cublx *cublx)
{
	t_data	*data;

	data = cublx->user->param;
	if (cublx->btn(cublx, XK_w))
		move_player(data, data->player.move_speed);
	if (cublx->btn(cublx, XK_s))
		move_player(data, -data->player.move_speed);
	if (cublx->btnp(cublx, XK_Escape))
		exit_game(data, cublx, 0);
	return (0);
}

int	main(void)
{
	t_data	*data;
	t_cublx	*cublx;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (1);
	read_map(data);
	cublx = cublx_new(WIDTH, HEIGHT, "cub3D");
	init_game(data, cublx);
	load_all_textures(data, cublx);
	cublx_set_user_param(cublx, data);
	cublx_set_hooks(cublx, update, draw, dest);
	mlx_hook(cublx->win, DestroyNotify, 0, destroy_window, data);
	cublx_run(cublx);
	cublx_del(&cublx);
	return (0);
}
