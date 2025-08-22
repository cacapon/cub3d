/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 07:04:18 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/22 21:25:13 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"

t_cublx	*cublx_new(int w, int h, char *title)
{
	t_cublx	*cublx;

	cublx = _cublx_calloc(1, sizeof(t_cublx));
	if (!cublx)
		return (NULL);
	cublx->mlx = mlx_init();
	if (!cublx->mlx)
		return (cublx_del(&cublx), NULL);
	cublx->win = mlx_new_window(cublx->mlx, w, h, title);
	if (!cublx->win)
		return (cublx_del(&cublx), NULL);
	cublx->btn = _cublx_btn;
	_cublx_key_state_init(cublx);
	_cublx_key_just_pressed_init(cublx);
	return (cublx);
}
