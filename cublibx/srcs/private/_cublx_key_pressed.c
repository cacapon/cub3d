/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cublx_key_pressed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:00:33 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/24 16:16:06 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"
#include <stdio.h>

int	_cublx_key_pressed(int keycode, t_cublx *cublx)
{
	if (keycode < 0 || keycode > KEY_MAX)
		return (1);
	cublx->_key_state[keycode] = 1;
	cublx->_key_just_pressed[keycode] = 1;
	return (0);
}
