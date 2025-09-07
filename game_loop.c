/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:54:44 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/07 19:41:20 by yookamot         ###   ########.fr       */
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
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->front_buffer.img, 0, 0);
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
	return (0);
}
