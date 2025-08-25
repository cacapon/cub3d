/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cublx_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:19:03 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/24 18:25:30 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"

int	_cublx_loop(t_cublx *cublx)
{
	cublx->user->update(cublx);
	cublx->user->draw(cublx);
	mlx_put_image_to_window(
		cublx->mlx, cublx->win,
		cublx->main_view[cublx->view_switch].img,
		0, 0);
	cublx->view_switch += (cublx->view_switch + 1) % 2;
	_cublx_key_just_pressed_init(cublx);
	return (0);
}
