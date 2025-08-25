/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx_set_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:30:20 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/24 16:04:35 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"

void	cublx_set_hooks(
	t_cublx *cublx,
	int (*update)(t_cublx *),
	int (*draw)(t_cublx *),
	int (*destructor)(t_cublx *)
)
{
	cublx->user->update = update;
	cublx->user->draw = draw;
	cublx->user->destructor = destructor;
	mlx_loop_hook(cublx->mlx, _cublx_loop, cublx);
	mlx_hook(cublx->win, 2, (1L << 0), _cublx_key_pressed, cublx);
	mlx_hook(cublx->win, 3, (1L << 1), _cublx_key_released, cublx);
}
