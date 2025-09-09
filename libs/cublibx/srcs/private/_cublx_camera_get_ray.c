/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cublx_camera_get_ray.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:36:20 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/01 18:18:11 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx_camera.h"

t_vec2	_cublx_camera_get_ray(t_camera *self, int x, int w)
{
	double	camera_x;
	t_vec2	ray;

	camera_x = 2.0 * x / (double)w - 1.0;
	ray.x = self->dir.x + self->plane.x * camera_x;
	ray.y = self->dir.y + self->plane.y * camera_x;
	return (ray);
}
