/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:30:12 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/09 15:35:08 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// TODO
int	dest(t_cublx *cublx)
{
	t_data	*data;
	
	data = cublx->user->param;
	cublx->free_tex(cublx, &data->textures.north);
	cublx->free_tex(cublx, &data->textures.east);
	cublx->free_tex(cublx, &data->textures.west);
	cublx->free_tex(cublx, &data->textures.south);
	cublx_camera_del(&data->player.camera);
	if (data && data->map)
		free_array(data->map);
	if (data)
		free(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_cublx	*cublx;

	if (argc != 2)
		error_exit(NULL, -1, "Invalid number of arguments.");
	cublx = cublx_new(WIDTH, HEIGHT, "cub3D");
	if (!cublx)
		error_exit(NULL, -1, "Failed to allocate cublx.");
	cublx_set_hooks(cublx, game_loop, draw_buffer, dest);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		error_exit(NULL, -1, "Failed to allocate memory.");
	init_game(data);
	cublx_set_user_param(cublx, data);
	parse_cub_file(cublx, argv[1]);
	cublx_run(cublx);
	cublx_del(&cublx);
	return (0);
}
