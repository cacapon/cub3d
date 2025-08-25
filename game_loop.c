/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:54:44 by yookamot          #+#    #+#             */
/*   Updated: 2025/08/25 18:54:16 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// playerの座標更新
static void	move_player(t_data *data, double dir_x, double dir_y)
{
	double	speed;
	double	new_x;
	double	new_y;

	speed = data->player.move_speed;
	new_x = data->player.pos_x + dir_x * speed;
	new_y = data->player.pos_y + dir_y * speed;
	if (data->map[(int)data->player.pos_y][(int)new_x] != '1'
		&& data->map[(int)data->player.pos_y][(int)new_x] != '2')
		data->player.pos_x = new_x;
	if (data->map[(int)new_y][(int)data->player.pos_x] != '1'
		&& data->map[(int)new_y][(int)data->player.pos_x] != '2')
		data->player.pos_y = new_y;
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
	char	buffer[100];

	// プレイヤー座標を文字列に変換（小数点以下2桁まで表示）
	sprintf(buffer, "Player pos: x = %.2f, y = %.2f", data->player.pos_x,
		data->player.pos_y);
	// 黒で描画 (色は16進で指定: 0xRRGGBB)
	mlx_string_put(data->mlx, data->win, 10, 20, 0xFF0000, buffer);
}

// 1フレームごとに実行されるループ関数
int	game_loop(t_data *data)
{
	if (data->player.move_forward && !data->front_lock)
		move_player(data, data->player.dir_x, data->player.dir_y);
	if (data->player.move_backward)
		move_player(data, data->player.dir_x, -data->player.dir_y);
	if (data->player.strafe_left && !data->left_lock)
		move_player(data, data->player.dir_y, -data->player.dir_x);
	if (data->player.strafe_right && !data->right_lock)
		move_player(data, -data->player.dir_y, data->player.dir_x);
	// if (data->player.turn_left)
	// 	rotate_player(data, -data->player.rot_speed);
	// if (data->player.turn_right)
	// 	rotate_player(data, data->player.rot_speed);
	draw_buffer(data);
	// printf("Player Position: (%f, %f)\n", data->player.pos_x,
	// 	data->player.pos_y);
	display_player_position(data);
	return (0);
}
