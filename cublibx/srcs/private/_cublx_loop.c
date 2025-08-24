/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cublx_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:19:03 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/24 15:45:00 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"

int	_cublx_loop(t_cublx *cublx)
{
	cublx->user->update(cublx);
	cublx->user->draw(cublx);
	_cublx_key_just_pressed_init(cublx);
	return (0);
}
