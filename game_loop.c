/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:54:44 by yookamot          #+#    #+#             */
/*   Updated: 2025/08/21 23:35:22 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// playerの座標更新
static void	move_player(t_data *data, double speed)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_x * speed;
	new_y = data->player.pos_y + data->player.dir_y * speed;
	if (data->map[(int)data->player.pos_y][(int)new_x] != '1')
		data->player.pos_x = new_x;
	if (data->map[(int)new_y][(int)data->player.pos_x] != '1')
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

// 1フレームごとに実行されるループ関数
int	game_loop(t_data *data)
{
	if (data->player.move_forward)
		move_player(data, data->player.move_speed);
	if (data->player.move_backward)
		move_player(data, -data->player.move_speed);
	// if (data->player.strafe_left)
	// 	strafe_player(data, -data->player.move_speed);
	// if (data->player.strafe_right)
	// 	strafe_player(data, data->player.move_speed);
	// if (data->player.turn_left)
	// 	rotate_player(data, -data->player.rot_speed);
	// if (data->player.turn_right)
	// 	rotate_player(data, data->player.rot_speed);
	draw_buffer(data);
	// printf("Player Position: (%f, %f)\n", data->player.pos_x,
	// 	data->player.pos_y);
	return (0);
}
