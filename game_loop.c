/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:54:44 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/01 21:23:34 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate_player(t_data *data, double speed)
{
	double	len;

	data->player.angle += speed;
	if (data->player.angle < 0)
		data->player.angle += 2 * PI;
	if (data->player.angle > 2 * PI)
		data->player.angle -= 2 * PI;
	data->player.dir_x = cos(data->player.angle);
	data->player.dir_y = sin(data->player.angle);
	len = sqrt(data->player.dir_x * data->player.dir_x + data->player.dir_y
			* data->player.dir_y);
	data->player.dir_x /= len;
	data->player.dir_y /= len;
}

static void	move_player(t_data *data, double dir_x, double dir_y)
{
	double	speed;
	double	new_x;
	double	new_y;
	double	fx;
	double	fy;

	speed = data->player.move_speed;
	new_x = data->player.pos_x + dir_x * speed;
	new_y = data->player.pos_y + dir_y * speed;
	fx = new_x - floor(new_x);
	fy = new_y - floor(new_y);
	if (data->map[(int)data->player.pos_y][(int)new_x] != '1')
	{
		if (!(fx < 0.35 && data->map[(int)data->player.pos_y][(int)new_x
				- 1] == '1') && !(fx > 0.65
				&& data->map[(int)data->player.pos_y][(int)new_x + 1] == '1'))
			data->player.pos_x = new_x;
	}
	if (data->map[(int)new_y][(int)data->player.pos_x] != '1')
	{
		if (!(fy < 0.35 && data->map[(int)new_y
				- 1][(int)data->player.pos_x] == '1') && !(fy > 0.65
				&& data->map[(int)new_y + 1][(int)data->player.pos_x] == '1'))
			data->player.pos_y = new_y;
	}
}

// レイキャスティングを行った上でバッファをウィンドウに表示
static void	draw_buffer(t_data *data)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		ray_casting(data, i);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->front_buffer.img, 0, 0);
}

void	display_player_position(t_data *data)
{
	char	buffer[200];

	// プレイヤー座標、方向ベクトル、角度を文字列に変換（小数点以下2桁）
	// 角度を度に変換: rad × 180 / PI
	sprintf(buffer,
			"Player pos: x = %.2f, y = %.2f | "
			"dir_x = %.2f, dir_y = %.2f | "
			"angle = %.2f deg",
			data->player.pos_x,
			data->player.pos_y,
			data->player.dir_x,
			data->player.dir_y,
			data->player.angle * 180.0 / PI);
	// 赤で描画 (色は16進で指定: 0xRRGGBB)
	mlx_string_put(data->mlx, data->win, 10, 20, 0xFF0000, buffer);
}

// 1フレームごとに実行されるループ関数
int	game_loop(t_data *data)
{
	if (data->player.turn_left)
		rotate_player(data, -data->player.rot_speed);
	if (data->player.turn_right)
		rotate_player(data, data->player.rot_speed);
	if (data->player.move_forward)
		move_player(data, data->player.dir_x, data->player.dir_y);
	if (data->player.move_backward)
		move_player(data, -data->player.dir_x, -data->player.dir_y);
	if (data->player.strafe_left)
		move_player(data, data->player.dir_y, -data->player.dir_x);
	if (data->player.strafe_right)
		move_player(data, -data->player.dir_y, data->player.dir_x);
	draw_buffer(data);
	display_player_position(data);
	return (0);
}
