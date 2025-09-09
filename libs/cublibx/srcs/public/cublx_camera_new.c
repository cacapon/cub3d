/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx_camera_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:18:39 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/09 17:12:44 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx_camera.h"
#include <math.h>

/**
 * @brief Create a camera instance.
 *
 * @param pos
 * @param dir
 * @param fov_deg
 * @return t_camera*
 * @note FOV should be given in degrees.
 */
t_camera	*cublx_camera_new(t_vec2 pos, t_vec2 dir, double fov_deg)
{
	t_camera	*camera;
	t_vec2		perp;
	double		scale;
	double		fov;

	fov = fov_deg * M_PI / 180.0;
	if (fov <= 0.0 || fov >= M_PI)
		return (NULL);
	camera = cublx_calloc(1, sizeof(t_camera));
	if (!camera)
		return (NULL);
	camera->pos = pos;
	camera->dir = dir;
	camera->fov_deg = fov_deg;
	perp = (t_vec2){.x = -dir.y, .y = dir.x};
	scale = tan(fov / 2.0);
	camera->plane = (t_vec2){.x = perp.x * scale, .y = perp.y * scale};
	camera->get_ray = _cublx_camera_get_ray;
	camera->move = _cublx_camera_move;
	camera->rotate = _cublx_camera_rotate;
	camera->set_fov = _cublx_camera_set_fov;
	camera->set_view = _cublx_camera_set_view;
	return (camera);
}
