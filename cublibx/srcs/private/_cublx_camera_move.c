/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cublx_camera_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:36:14 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/01 18:17:50 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx_camera.h"

void	_cublx_camera_move(t_camera *self, t_vec2 delta)
{
	self->pos.x += delta.x;
	self->pos.y += delta.y;
}
