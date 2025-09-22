/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _allocate_view.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:02:08 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/22 08:28:27 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"

int	_allocate_view(t_cublx_img *view, t_cublx *cublx, int w, int h)
{
	if (!cublx)
		return (cublx_perror(E_CUBLX_000), 1);
	view->img = mlx_new_image(cublx->mlx, w, h);
	if (!view->img)
		return (cublx_perror(E_CUBLX_004), 1);
	view->addr = mlx_get_data_addr(
			view->img,
			&view->bits_per_pixel,
			&view->line_length,
			&view->endian);
	if (!view->addr)
		return (cublx_perror(E_CUBLX_005), 1);
	return (0);
}
