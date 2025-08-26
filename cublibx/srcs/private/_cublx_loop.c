/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cublx_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:19:03 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/26 10:17:06 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"

int	_cublx_loop(t_cublx *cublx)
{
	cublx->user->update(cublx);
	cublx->user->draw(cublx);
	mlx_put_image_to_window(
		cublx->mlx, cublx->win,
		cublx->main_v.view[cublx->main_v.sw].img,
		0, 0);
	cublx->main_v.sw += (cublx->main_v.sw + 1) % 2;
	_cublx_key_just_pressed_init(cublx);
	return (0);
}
