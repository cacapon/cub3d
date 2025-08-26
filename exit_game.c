/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:13:16 by yookamot          #+#    #+#             */
/*   Updated: 2025/08/25 17:01:23 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	destroy_window(t_cublx *cublx)
{
	exit_game(cublx->user->param, 0, cublx);
}

static void	cleanup_textures(t_data *data, t_cublx *cublx)
{
	if (data->textures.north.img)
		mlx_destroy_image(cublx->mlx, data->textures.north.img);
	if (data->textures.south.img)
		mlx_destroy_image(cublx->mlx, data->textures.south.img);
	if (data->textures.east.img)
		mlx_destroy_image(cublx->mlx, data->textures.east.img);
	if (data->textures.west.img)
		mlx_destroy_image(cublx->mlx, data->textures.west.img);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	cleanup_buffers(t_data *data, t_cublx *cublx)
{
	if (data->front_buffer.img)
		mlx_destroy_image(cublx->mlx, data->front_buffer.img);
	if (data->back_buffer.img)
		mlx_destroy_image(cublx->mlx, data->back_buffer.img);
}

void	exit_game(t_data *data, int status, t_cublx *cublx)
{
	if (!data)
		exit(status);
	cleanup_textures(data, cublx);
	if (cublx->win)
		mlx_destroy_window(cublx->mlx, cublx->win);
	if (data->map)
		free_array(data->map);
	cleanup_buffers(data, cublx);
	if (cublx->mlx)
	{
		mlx_destroy_display(cublx->mlx);
		free(cublx->mlx);
	}
	free(data);
	exit(status);
}
