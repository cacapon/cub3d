/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cublx_camera_set_view.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:04:54 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/09 16:33:18 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx_camera.h"
#include <math.h>

void	_cublx_camera_set_view(
	t_camera *self,
	t_vec2 pos,
	t_vec2 dir,
	double fov_deg)
{
	double	fov;
	double	scale;
	t_vec2	perp;

	self->pos = pos;
	self->dir = dir;
	self->fov_deg = fov_deg;
	fov = fov_deg * M_PI / 180.0;
	scale = tan(fov / 2.0);
	perp = (t_vec2){.x = -dir.y, .y = dir.x};
	self->plane = (t_vec2){.x = perp.x * scale, .y = perp.y * scale};
}
