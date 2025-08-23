/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cublx_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:19:03 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/22 21:44:07 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"

int	_cublx_loop(void *_cublx)
{
	t_cublx	*cublx;

	cublx = (t_cublx *)_cublx;
	cublx->user->update(cublx->user->param);
	cublx->user->draw(cublx->user->param);
	_cublx_key_just_pressed_init(cublx);
	return (0);
}
