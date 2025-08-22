/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cublx_key_released.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:00:33 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/22 21:12:39 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"

/**
 * @brief The key released is set to 0.
 * 
 * @param self 
 * @param keycode 
 * @return int 0: Success 1: Invalid key code
 */
int	_cublx_key_released(t_cublx *self, int keycode)
{
	if (keycode < 0 || keycode > KEY_MAX)
		return (1);
	self->_key_state[keycode] = 0;
	return (0);
}
