/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cublx_camera_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:36:14 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/02 10:25:46 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx_camera.h"

/**
 * @brief Move by delta in the direction of the camera.
 * 
 * @param self 
 * @param delta 
 */
void	_cublx_camera_move(t_camera *self, t_vec2 delta)
{
	self->pos.x += -delta.y * self->dir.x + delta.x * self->plane.x;
	self->pos.y += -delta.y * self->dir.y + delta.x * self->plane.y;
}
