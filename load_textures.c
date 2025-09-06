/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:06:04 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/05 19:48:48 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// texture画像の読み込み
void	load_all_textures(t_cublx *cublx, t_data *data)
{
	cublx->load_xpm(cublx, &data->textures.north, "textures/north.xpm");
	cublx->load_xpm(cublx, &data->textures.south, "textures/south.xpm");
	cublx->load_xpm(cublx, &data->textures.east, "textures/east.xpm");
	cublx->load_xpm(cublx, &data->textures.west, "textures/west.xpm");
}
