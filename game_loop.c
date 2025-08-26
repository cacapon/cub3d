/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:54:44 by yookamot          #+#    #+#             */
/*   Updated: 2025/08/26 10:29:21 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// playerの座標更新
void	move_player(t_data *data, double speed)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_x * speed;
	new_y = data->player.pos_y + data->player.dir_y * speed;
	if (data->map[(int)data->player.pos_y][(int)new_x] != '1'
		&& data->map[(int)data->player.pos_y][(int)new_x] != '2')
		data->player.pos_x = new_x;
	if (data->map[(int)new_y][(int)data->player.pos_x] != '1'
		&& data->map[(int)new_y][(int)data->player.pos_x] != '2')
		data->player.pos_y = new_y;
}

// レイキャスティングを行った上でバッファをウィンドウに表示
void	draw_buffer(t_cublx *cublx)
{
	int			i;
	t_data		*data;
	void		*current_view_img;

	i = 0;
	data = cublx->user->param;
	while (i < WIDTH)
	{
		ray_casting(data, i, cublx);
		i++;
	}
	current_view_img = cublx->main_v.view[cublx->main_v.sw].img;
	mlx_put_image_to_window(cublx->mlx, cublx->win, current_view_img, 0, 0);
}

void	display_player_position(t_data *data, t_cublx *cublx)
{
	char	buffer[100];

	// プレイヤー座標を文字列に変換（小数点以下2桁まで表示）
	sprintf(buffer, "Player pos: x = %.2f, y = %.2f", data->player.pos_x,
		data->player.pos_y);
	// 黒で描画 (色は16進で指定: 0xRRGGBB)
	mlx_string_put(cublx->mlx, cublx->win, 10, 20, 0xFF0000, buffer);
}

// 1フレームごとに実行されるループ関数
int	game_loop(t_cublx *cublx)
{
	t_data	*data;

	data = cublx->user->param;
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
	draw_buffer(cublx);
	// printf("Player Position: (%f, %f)\n", data->player.pos_x,
	// 	data->player.pos_y);
	display_player_position(data, cublx);
	return (0);
}
