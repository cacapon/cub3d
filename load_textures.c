/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:06:04 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/05 19:34:10 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
static void	cublx->load_xpm(cublx, t_data *data, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(data->mlx, path, &img->size.x,
			&img->size.y);
	if (!img->img)
		exit_game(data, 1);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		exit_game(data, 1);
}
*/

// texture画像の読み込み
void	load_all_textures(t_cublx *cublx, t_data *data)
{
	cublx->load_xpm(cublx, &data->textures.north, "textures/north.xpm");
	cublx->load_xpm(cublx, &data->textures.south, "textures/south.xpm");
	cublx->load_xpm(cublx, &data->textures.east, "textures/east.xpm");
	cublx->load_xpm(cublx, &data->textures.west, "textures/west.xpm");
}
