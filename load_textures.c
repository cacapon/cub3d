/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:06:04 by yookamot          #+#    #+#             */
/*   Updated: 2025/08/25 17:08:41 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_xpm(t_data *data, t_img *img, char *path, t_cublx *cublx)
{
	img->img = mlx_xpm_file_to_image(cublx->mlx, path, &img->width,
			&img->height);
	if (!img->img)
		exit_game(data, 1, cublx);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		exit_game(data, 1, cublx);
}

// texture画像の読み込み
void	load_all_textures(t_data *data, t_cublx *cublx)
{
	load_xpm(data, &data->textures.north, "textures/north.xpm", cublx);
	load_xpm(data, &data->textures.south, "textures/south.xpm", cublx);
	// load_xpm(data, &data->textures.east, "textures/east.xpm");
	// load_xpm(data, &data->textures.west, "textures/west.xpm");
}
