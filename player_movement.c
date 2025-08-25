/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:00:33 by yookamot          #+#    #+#             */
/*   Updated: 2025/08/25 17:10:50 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//キーが押下のときに実行される、フラグを建てる
int	key_press(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		;//exit_game(data, 0);
	else if (keycode == XK_w)
		data->player.move_forward = 1;
	else if (keycode == XK_s)
		data->player.move_backward = 1;
	else if (keycode == XK_a)
		data->player.strafe_left = 1;
	else if (keycode == XK_d)
		data->player.strafe_right = 1;
	else if (keycode == 65361)
		data->player.turn_left = 1;
	else if (keycode == 65363)
		data->player.turn_right = 1;
	return (0);
}

//キーが離上のときに実行される、フラグを解除
int	key_release(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		;//exit_game(data, 0);
	else if (keycode == XK_w)
		data->player.move_forward = 0;
	else if (keycode == XK_s)
		data->player.move_backward = 0;
	else if (keycode == XK_a)
		data->player.strafe_left = 0;
	else if (keycode == XK_d)
		data->player.strafe_right = 0;
	else if (keycode == 65361)
		data->player.turn_left = 0;
	else if (keycode == 65363)
		data->player.turn_right = 0;
	return (0);
}
