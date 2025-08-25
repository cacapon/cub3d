/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:15:23 by yookamot          #+#    #+#             */
/*   Updated: 2025/08/25 17:19:01 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// player構造体の初期化
static void	init_player(t_data *data)
{
	data->player.pos_x = 2.5;
	data->player.pos_y = 4.5;
	data->player.dir_x = 0.0;
	data->player.dir_y = -0.1;
	data->player.move_speed = 0.05;
	data->player.rot_speed = 0.03;
	data->player.move_forward = 0;
	data->player.move_backward = 0;
	data->player.strafe_left = 0;
	data->player.strafe_right = 0;
	data->player.turn_left = 0;
	data->player.turn_right = 0;
	data->player.angle = PI / 2;
}

// bufferの初期化
static void	init_buffer(t_data *data)
{
	data->front_buffer.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->front_buffer.addr = mlx_get_data_addr(data->front_buffer.img,
			&data->front_buffer.bits_per_pixel, &data->front_buffer.line_length,
			&data->front_buffer.endian);
	data->back_buffer.img = NULL;
	data->back_buffer.addr = NULL;
	// data->back_buffer.img = mlx_new_image(data->mlx, WIDTH,
	// 		HEIGHT);
	// data->back_buffer.addr = mlx_get_data_addr(data->back_buffer.img,
	// 		&data->back_buffer.bits_per_pixel, &data->back_buffer.line_length,
	// 		&data->back_buffer.endian);
	data->current_buffer = 0;
}

// data構造体の初期化
void	init_game(t_data *data)
{
	data->textures.north.img = NULL;
	data->textures.south.img = NULL;
	data->textures.east.img = NULL;
	data->textures.west.img = NULL;
	data->floor_color = 16711680;
	data->ceiling_color = 255;
	data->front_lock;
	init_player(data);
	init_buffer(data);
}
