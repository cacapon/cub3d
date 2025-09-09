/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:15:23 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/09 17:10:53 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_texture(t_img *tex)
{
	tex->img = NULL;
	tex->addr = NULL;
	tex->bits_per_pixel = 0;
	tex->line_length = 0;
	tex->endian = 0;
	tex->size = cublx_vec2i(0, 0);
}

// player構造体の初期化
static void	init_player(t_data *data)
{
	t_vec2	p_pos;
	t_vec2	p_dir;

	p_pos = cublx_vec2(0.0, 0.0);
	p_dir = cublx_vec2(0.0, 0.0);
	data->player.camera = cublx_camera_new(p_pos, p_dir, FOV);
	data->player.move_speed = 0.04;
	data->player.rot_speed = 0.04;
}

// data構造体の初期化
//error_exit(data, -1, "Failed to initialize MiniLibX.");
//error_exit(data, -1, "Failed to create window.");
void	init_game(t_data *data)
{
	init_texture(&data->textures.north);
	init_texture(&data->textures.south);
	init_texture(&data->textures.east);
	init_texture(&data->textures.west);
	data->floor_color = -1;
	data->ceiling_color = -1;
	data->map = NULL;
	init_player(data);
}
