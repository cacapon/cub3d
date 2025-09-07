/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:18:54 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/07 19:54:08 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_grid_in_minimap(int *dst, int i, int j, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			dst[(i * 10 + 20 + y) * WIDTH + (j * 10 + 20 + x)] = color;
			x++;
		}
		y++;
	}
}

static void	draw_player_position_in_minimap(t_data *data, int *dst)
{
	int	x;
	int	y;

	y = 0;
	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			dst[((int)(data->player.pos_y * 10) + 18 + y) * WIDTH
				+ (int)(data->player.pos_x * 10) + 18 + x] = 16711935;
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				draw_grid_in_minimap((int *)data->front_buffer.addr, i, j, 0);
			else if (data->map[i][j] == '0' || data->map[i][j] == 'N'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W'
				|| data->map[i][j] == 'S')
				draw_grid_in_minimap((int *)data->front_buffer.addr, i, j,
					16777215);
			j++;
		}
		i++;
	}
	draw_player_position_in_minimap(data, (int *)data->front_buffer.addr);
}
