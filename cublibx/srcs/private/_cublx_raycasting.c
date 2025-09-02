/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cublx_raycasting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:46:51 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/02 09:43:41 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"
#include <math.h>

static double	_get_perp_wall_dist(
	t_raycasting *rc,
	t_camera *cmr,
	char **map)
{
	int	side;

	while (1)
	{
		if (rc->side_dist.x < rc->side_dist.y)
		{
			rc->side_dist.x += rc->delta_dist.x;
			rc->grid_pos.x += rc->step.x;
			side = HIT_XLINE;
		}
		else
		{
			rc->side_dist.y += rc->delta_dist.y;
			rc->grid_pos.y += rc->step.y;
			side = HIT_YLINE;
		}
		if (map[rc->grid_pos.y][rc->grid_pos.x] == '1')
			break ;
	}
	if (side == HIT_XLINE)
		return ((rc->grid_pos.x - cmr->pos.x + (1 - rc->step.x) / 2)
			/ rc->ray_dir.x);
	else
		return ((rc->grid_pos.y - cmr->pos.y + (1 - rc->step.y) / 2)
			/ rc->ray_dir.y);
}

static t_vec2i	_get_step(t_vec2 ray)
{
	t_vec2i	step;

	if (ray.x < 0)
		step.x = -1;
	else
		step.x = 1;
	if (ray.y < 0)
		step.y = -1;
	else
		step.y = 1;
	return (step);
}

static t_vec2	_get_side_dist(t_raycasting rc, t_camera *camera)
{
	t_vec2	side_dist;

	if (rc.ray_dir.x < 0)
		side_dist.x = (camera->pos.x - rc.grid_pos.x) * rc.delta_dist.x;
	else
		side_dist.x = (rc.grid_pos.x + 1.0 - camera->pos.x) * rc.delta_dist.x;
	if (rc.ray_dir.y < 0)
		side_dist.y = (camera->pos.y - rc.grid_pos.y) * rc.delta_dist.y;
	else
		side_dist.y = (rc.grid_pos.y + 1.0 - camera->pos.y) * rc.delta_dist.y;
	return (side_dist);
}

int	_cublx_raycasting(t_cublx *self, t_camera *camera,  t_raycasting rc)
{
	int	i;
	int	cail_end;
	int	wall_end;	

	rc.grid_pos = (t_vec2i){(int)camera->pos.x, (int)camera->pos.y};
	rc.ray_dir = camera->get_ray(camera, rc.x, self->win_size.x);
	rc.step = _get_step(rc.ray_dir);
	rc.delta_dist = (t_vec2){fabs(1 / rc.ray_dir.x), fabs(1 / rc.ray_dir.y)};
	rc.side_dist = _get_side_dist(rc, camera);
	rc.perp_wall_dist = _get_perp_wall_dist(&rc, camera, rc.map);
	rc.line_h = (int)(self->win_size.y / rc.perp_wall_dist);
	i = 0;
	cail_end = -rc.line_h / 2 + self->win_size.y / 2;
	wall_end = rc.line_h / 2 + self->win_size.y / 2;
	while (i < self->win_size.y)
	{
		if (i < cail_end)
			self->pset(self, rc.x, i, rc.ceiling_color);
		if (cail_end <= i && i < wall_end)
			self->pset(self, rc.x, i, rc.wall_color);
		if (wall_end <= i && i < self->win_size.y)
			self->pset(self, rc.x, i, rc.floor_color);
		i++;
	}
	return (0);
}
