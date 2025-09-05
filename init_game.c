/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:15:23 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/05 19:43:32 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// player構造体の初期化
static void	init_player(t_data *data)
{
	double	angle;
	t_vec2	p_pos;
	t_vec2	p_dir;

	angle = PI * 3 / 2;
	p_pos = cublx_vec2(2.5, 4.5);
	p_dir = cublx_vec2(cos(angle), sin(angle));
	data->player.camera = cublx_camera_new(p_pos, p_dir, 66.0);
	data->player.move_speed = 0.04;
	data->player.rot_speed = 0.04;
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
	init_player(data);
}
