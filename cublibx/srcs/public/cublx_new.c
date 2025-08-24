/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 07:04:18 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/24 06:52:46 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"

t_cublx	*cublx_new(int w, int h, char *title)
{
	t_cublx	*cublx;

	cublx = _cublx_calloc(1, sizeof(t_cublx));
	if (!cublx)
		return (NULL);
	if (_allocate_mlx(cublx) != 0)
		return (cublx_del(&cublx), NULL);
	if (_allocate_mlx_win(cublx, w, h, title) != 0)
		return (cublx_del(&cublx), NULL);
	if (_allocate_cublx_user(cublx) != 0)
		return (cublx_del(&cublx), NULL);
	cublx->btn = _cublx_btn;
	_cublx_key_state_init(cublx);
	_cublx_key_just_pressed_init(cublx);
	return (cublx);
}
