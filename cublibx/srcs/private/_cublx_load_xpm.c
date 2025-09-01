/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cublx_load_xpm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:32:04 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/01 18:48:08 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"

/**
 * @brief Loads xpm data into the img structure.
 * 
 * @param self 
 * @param img 
 * @param path 
 * @return int 0:success 1:failed
 */
int	_cublx_load_xpm(t_cublx *self, t_cublx_img *img, char *xpm_path)
{
	void	*(*xpm_to_img)(void *mlx, char *fname, int *w, int *h);
	char	*(*get_addr)(void *img, int *bpp, int *line_h, int *endian);

	xpm_to_img = mlx_xpm_file_to_image;
	get_addr = mlx_get_data_addr;
	img->img = xpm_to_img(self->mlx, xpm_path, &img->size.x, &img->size.y);
	if (!img->img)
		return (1);
	img->addr = get_addr(img->img, &img->bits_per_pixel,
			&img->line_len, &img->endian);
	if (!img->addr)
		return (1);
	return (0);
}
