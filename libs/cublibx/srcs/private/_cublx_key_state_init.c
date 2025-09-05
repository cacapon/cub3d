/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cublx_key_state_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:00:33 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/22 21:24:41 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"

/**
 * @brief Initializes a state variable
 * 
 * that controls whether a key is pressed.
 * 
 * @param self 
 */
void	_cublx_key_state_init(t_cublx *self)
{
	int	i;

	i = 0;
	while (i < KEY_MAX)
		self->_key_state[i++] = 0;
}
