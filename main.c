/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:30:12 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/06 18:33:29 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		error_exit(NULL, -1, "Invalid number of arguments.");
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		error_exit(NULL, -1, "Failed to allocate memory.");
	init_game(data);
	parse_cub_file(data, argv[1]);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_hook(data->win, DestroyNotify, 0, destroy_window, data);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_loop(data->mlx);
	return (0);
}
