/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:36:57 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/19 17:00:24 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_player	_player_init(void)
{
	t_player	player;

	player.pos = (t_vector2){.x = 0.0, .y = 0.0};
	player.dir = (t_vector2){.x = 0.0, .y = -1.0};
	player.plane = (t_vector2){.x = 0.66, .y = 0.0};
	return (player);
}

/**
 * @brief
 *
 * @return t_data*
 */
t_data	*cub3d_init(void)
{
	t_data		*data;
	t_player	*t_player;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free(data), NULL);
	data->win_size = (t_vector2i){.x = WIN_W, .y = WIN_H};
	data->win = mlx_new_window(data->mlx, data->win_size.x, data->win_size.y,
			TITLE_NAME);
	if (!data->win)
		return (free(data->mlx), free(data), NULL);
	data->player = _player_init();
	return (data);
}
