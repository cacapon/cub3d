/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:30:12 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/05 20:18:32 by ttsubo           ###   ########.fr       */
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
	free_array(data->map);
	free(data);
	return (0);
}

int	main(void)
{
	t_data	*data;
	t_cublx	*cublx;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (1);
	read_map(data);
	init_game(data);
	cublx = cublx_new(WIDTH, HEIGHT, "cub3D");
	if (!cublx)
		return (free_array(data->map), free(data), 1);
	load_all_textures(cublx, data);
	cublx_set_hooks(cublx, game_loop, draw_buffer, dest);
	cublx_set_user_param(cublx, data);
	cublx_run(cublx);
	cublx_del(&cublx);
	return (0);
}
