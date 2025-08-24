/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cublx_btnp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 20:52:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/24 17:32:17 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"

int	_cublx_btnp(t_cublx *self, int keycode)
{
	if (keycode < 0 || keycode > KEY_MAX)
		return (0);
	return (self->_key_just_pressed[keycode]);
}
