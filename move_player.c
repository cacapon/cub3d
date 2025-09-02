/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:59:15 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/02 17:30:07 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_collision_x(t_data *data, double new_x, double current_y)
{
	int		map_y;
	int		map_x_left;
	int		map_x_right;
	double	y_frac;

	map_y = (int)current_y;
	map_x_left = (int)(new_x - 0.25);
	map_x_right = (int)(new_x + 0.25);
	y_frac = current_y - floor(current_y);
	if (data->map[map_y][map_x_left] == '1'
		|| data->map[map_y][map_x_right] == '1')
		return (false);
	if (y_frac <= 0.25)
	{
		if (data->map[map_y - 1][map_x_left] == '1' || data->map[map_y
			- 1][map_x_right] == '1')
			return (false);
	}
	if (y_frac >= 0.75)
	{
		if (data->map[map_y + 1][map_x_left] == '1' || data->map[map_y
			+ 1][map_x_right] == '1')
			return (false);
	}
	return (true);
}

static bool	check_collision_y(t_data *data, double current_x, double new_y)
{
	int		map_x;
	int		map_y_bottom;
	double	x_frac;
	int		map_y_top;

	map_x = (int)current_x;
	map_y_top = (int)(new_y - 0.25);
	map_y_bottom = (int)(new_y + 0.25);
	x_frac = current_x - floor(current_x);
	if (data->map[map_y_top][map_x] == '1'
		|| data->map[map_y_bottom][map_x] == '1')
		return (false);
	if (x_frac <= 0.25)
	{
		if (data->map[map_y_top][map_x - 1] == '1'
			|| data->map[map_y_bottom][map_x - 1] == '1')
			return (false);
	}
	if (x_frac >= 0.75)
	{
		if (data->map[map_y_top][map_x + 1] == '1'
			|| data->map[map_y_bottom][map_x + 1] == '1')
			return (false);
	}
	return (true);
}

void	move_player(t_data *data, double dir_x, double dir_y)
{
	double	speed;
	double	new_x;
	double	new_y;

	speed = data->player.move_speed;
	new_x = data->player.pos_x + dir_x * speed;
	new_y = data->player.pos_y + dir_y * speed;
	if (check_collision_x(data, new_x, data->player.pos_y))
		data->player.pos_x = new_x;
	if (check_collision_y(data, data->player.pos_x, new_y))
		data->player.pos_y = new_y;
}
