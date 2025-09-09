/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cublx_camera_set_fov.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:04:54 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/01 18:17:23 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx_camera.h"
#include <math.h>

void	_cublx_camera_set_fov(t_camera *self, double fov_deg)
{
	double	fov;
	double	scale;
	t_vec2	perp;

	fov = fov_deg * M_PI / 180.0;
	if (fov <= 0.0 || fov >= M_PI)
		return ;
	self->fov_deg = fov_deg;
	perp = (t_vec2){-self->dir.y, self->dir.x};
	scale = tan(fov / 2.0);
	self->plane = (t_vec2){.x = perp.x * scale, .y = perp.y * scale};
}
