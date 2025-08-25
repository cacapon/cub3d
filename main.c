/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:30:12 by yookamot          #+#    #+#             */
/*   Updated: 2025/08/20 19:35:27 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (1);
	read_map(data);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free_array(data->map), free(data), 1);
	init_game(data);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3D");
	if (!data->win)
		exit_game(data, 1);
	load_all_textures(data);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_hook(data->win, DestroyNotify, 0, destroy_window, data);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_loop(data->mlx);
	return (0);
}
