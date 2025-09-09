/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:18:54 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/08 23:35:32 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_grid_in_minimap(t_cublx *cublx, int i, int j, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			cublx->pset(cublx, (j * 10)+ 20 + x, (i * 10) + 20 + y, color);
			//dst[(i * 10 + 20 + y) * WIDTH + (j * 10 + 20 + x)] = color;
			x++;
		}
		y++;
	}
}

static void	draw_player_position_in_minimap(t_cublx *cublx)
{
	int		x;
	int		y;
	t_vec2i	draw_vec;
	t_data	*data;

	y = 0;
	data = cublx->user->param;
	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			draw_vec.x = x + (int)data->player.camera->pos.x;
			draw_vec.y = y + (int)data->player.camera->pos.y;
			cublx->pset(cublx, draw_vec.x, draw_vec.y, 16711935);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_cublx *cublx)
{
	int		i;
	int		j;
	t_data	*data;

	data = cublx->user->param;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				draw_grid_in_minimap(cublx, i, j, 0);
			else if (data->map[i][j] == '0' || data->map[i][j] == 'N'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W'
				|| data->map[i][j] == 'S')
				draw_grid_in_minimap(cublx, i, j, 16777215);
			j++;
		}
		i++;
	}
	draw_player_position_in_minimap(cublx);
}
