/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cublx_camera_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:36:14 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/22 07:30:56 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx_camera.h"
#include <math.h>
#include <stdbool.h>

static bool	_check_collision(t_vec2 pos, char **map, double margin)
{
	t_vec2i	g;

	g.x = (int)floor(pos.x);
	g.y = (int)floor(pos.y);
	if (map[g.y][g.x] == '1')
		return (true);
	if (pos.x - g.x < margin && map[g.y][g.x - 1] == '1')
		return (true);
	if ((g.x + 1) - pos.x < margin && map[g.y][g.x + 1] == '1')
		return (true);
	if (pos.y - g.y < margin && map[g.y - 1][g.x] == '1')
		return (true);
	if ((g.y + 1) - pos.y < margin && map[g.y + 1][g.x] == '1')
		return (true);
	return (false);
}

/**
 * @brief Move by delta in the direction of the camera.
 *
 * @param self
 * @param delta
 */
void	_cublx_camera_move(
	t_camera *self,
	t_vec2 delta,
	char **map,
	double margin)
{
	t_vec2	plane;
	t_vec2	new_pos;
	double	plane_len;

	plane = self->plane;
	plane_len = sqrt(plane.x * plane.x + plane.y * plane.y);
	new_pos = self->pos;
	new_pos.x += -delta.y * self->dir.x + delta.x * (plane.x / plane_len);
	new_pos.y += -delta.y * self->dir.y + delta.x * (plane.y / plane_len);
	if (!_check_collision(cublx_vec2(new_pos.x, self->pos.y), map, margin))
		self->pos.x = new_pos.x;
	if (!_check_collision(cublx_vec2(self->pos.x, new_pos.y), map, margin))
		self->pos.y = new_pos.y;
}
