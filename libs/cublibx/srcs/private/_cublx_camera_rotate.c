/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cublx_camera_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:36:12 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/01 18:17:41 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx_camera.h"
#include <math.h>

/**
 * @brief Rotate the camera in the "angle" direction.
 * 
 * The camera plane vector is also rotated
 * according to the direction of rotation.
 * 
 * @param self 
 * @param angle 
 */
void	_cublx_camera_rotate(t_camera *self, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = self->dir.x;
	self->dir.x = old_dir_x * cos(angle) - self->dir.y * sin(angle);
	self->dir.y = old_dir_x * sin(angle) + self->dir.y * cos(angle);
	old_plane_x = self->plane.x;
	self->plane.x = old_plane_x * cos(angle) - self->plane.y * sin(angle);
	self->plane.y = old_plane_x * sin(angle) + self->plane.y * cos(angle);
}
