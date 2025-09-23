/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx_set_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:30:20 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/22 08:50:42 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"
#include <stdlib.h>

static int	_cublx_win_exit(t_cublx *cublx)
{
	cublx->quit(cublx, EXIT_SUCCESS);
	return (0);
}

/**
 * @brief Set the drawing, update, and user-side destractor
 * to cublx hooks.
 * 
 * @param cublx 
 * @param update 
 * @param draw 
 * @param destructor 
 * @return 0:succsess 1:failed
 * @note pre: You must pass a cublx pointer allocated with cublx_new().
 * 
 * pre: Drawing and updating require passing defined function pointers.
 * 
 * opt: destractor accepts NULL.
 */
int	cublx_set_hooks(
	t_cublx *cublx,
	int (*update)(t_cublx *),
	int (*draw)(t_cublx *),
	int (*destructor)(t_cublx *))
{
	if (!cublx || !update || !draw)
		return (cublx_perror(E_CUBLX_000), 1);
	cublx->user->update = update;
	cublx->user->draw = draw;
	cublx->user->destructor = destructor;
	mlx_loop_hook(cublx->mlx, _cublx_loop, cublx);
	mlx_hook(cublx->win, 2, (1L << 0), _cublx_key_pressed, cublx);
	mlx_hook(cublx->win, 3, (1L << 1), _cublx_key_released, cublx);
	mlx_hook(cublx->win, 17, 0, _cublx_win_exit, cublx);
	return (0);
}
