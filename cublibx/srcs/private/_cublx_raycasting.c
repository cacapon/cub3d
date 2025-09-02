/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cublx_raycasting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:46:51 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/02 15:46 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"
#include <math.h>

static double	_get_perp_wall_dist(
	t_raycasting *rc,
	t_camera *cmr,
	char **map)
{
	while (1)
	{
		if (rc->side_dist.x < rc->side_dist.y)
		{
			rc->side_dist.x += rc->delta_dist.x;
			rc->grid_pos.x += rc->step.x;
			rc->side = HIT_XLINE;
		}
		else
		{
			rc->side_dist.y += rc->delta_dist.y;
			rc->grid_pos.y += rc->step.y;
			rc->side = HIT_YLINE;
		}
		if (map[rc->grid_pos.y][rc->grid_pos.x] == '1')
			break ;
	}
	if (rc->side == HIT_XLINE)
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

static void _draw_line(t_cublx *self, t_camera *camera, t_raycasting rc)
{
	int		i;
	int		color;
	int		cail_end;
	int		wall_end;
	t_vec2	hit;
	double	wall_x;
	t_img	*tex;
	int		tex_x;
	int		tex_y;
	int		d;

	i = 0;
	cail_end = -rc.line_h / 2 + self->win_size.y / 2;
	wall_end = rc.line_h / 2 + self->win_size.y / 2;
	hit.x = camera->pos.x + rc.ray_dir.x * rc.perp_wall_dist;
	hit.y = camera->pos.y + rc.ray_dir.y * rc.perp_wall_dist;
	if (rc.side == HIT_XLINE)
	{
		wall_x = hit.y - floor(hit.y);
		if (rc.ray_dir.x > 0)
			tex = rc.texture_e;
		else
			tex = rc.texture_w;
	}
	else
	{
		wall_x = hit.x - floor(hit.x);
		if (rc.ray_dir.y > 0)
			tex = rc.texture_s;
		else
			tex = rc.texture_n;
	}
	tex_x = (int)(wall_x * tex->size.x);
	while (i < self->win_size.y)
	{
		if (i < cail_end)
			self->pset(self, rc.x, i, rc.ceiling_color);
		if (cail_end <= i && i < wall_end)
		{

			d = (i * 256 - self->win_size.y * 128 + rc.line_h * 128);
			tex_y = ((d * tex->size.y) / rc.line_h) / 256;
			color = cublx_get_tex_color(tex, tex_x, tex_y);
			self->pset(self, rc.x, i, color);
		}
		if (wall_end <= i && i < self->win_size.y)
			self->pset(self, rc.x, i, rc.floor_color);
		i++;
	}
}

int	_cublx_raycasting(t_cublx *self, t_camera *camera,  t_raycasting rc)
{
	rc.grid_pos = (t_vec2i){(int)camera->pos.x, (int)camera->pos.y};
	rc.ray_dir = camera->get_ray(camera, rc.x, self->win_size.x);
	rc.step = _get_step(rc.ray_dir);
	rc.delta_dist = (t_vec2){fabs(1 / rc.ray_dir.x), fabs(1 / rc.ray_dir.y)};
	rc.side_dist = _get_side_dist(rc, camera);
	rc.perp_wall_dist = _get_perp_wall_dist(&rc, camera, rc.map);
	rc.line_h = (int)(self->win_size.y / rc.perp_wall_dist);
	_draw_line(self, camera, rc);
	return (0);
}
