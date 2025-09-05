/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cublx_draw_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:27:07 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/02 16:56:32 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"
#include <math.h>

static double	_get_wall_x(t_camera *camera, t_raycasting rc)
{
	t_vec2	hit;

	hit.x = camera->pos.x + rc.ray_dir.x * rc.perp_wall_dist;
	hit.y = camera->pos.y + rc.ray_dir.y * rc.perp_wall_dist;
	if (rc.side == HIT_XLINE)
		return (hit.y - floor(hit.y));
	else
		return (hit.x - floor(hit.x));
}

static t_img	*_get_tex(t_raycasting rc)
{
	if (rc.side == HIT_XLINE)
	{
		if (rc.ray_dir.x > 0)
			return (rc.texture_e);
		else
			return (rc.texture_w);
	}
	else
	{
		if (rc.ray_dir.y > 0)
			return (rc.texture_s);
		else
			return (rc.texture_n);
	}
}

static void	_draw_wall_line(
	t_cublx *self,
	t_raycasting rc,
	t_img *tex,
	t_vec2i tex_pos)
{
	int	d;
	int	color;

	d = (rc.draw_pos.y * 256 - self->win_size.y * 128 + rc.line_h * 128);
	tex_pos.y = ((d * tex->size.y) / rc.line_h) / 256;
	color = cublx_get_tex_color(tex, tex_pos.x, tex_pos.y);
	self->pset(self, rc.draw_pos.x, rc.draw_pos.y, color);
}

void	_cublx_draw_line(t_cublx *self, t_camera *camera, t_raycasting rc)
{
	int		i;
	int		cail_end;
	int		wall_end;
	t_img	*tex;
	t_vec2i	tex_pos;

	i = 0;
	cail_end = -rc.line_h / 2 + self->win_size.y / 2;
	wall_end = rc.line_h / 2 + self->win_size.y / 2;
	tex = _get_tex(rc);
	tex_pos.x = (int)(_get_wall_x(camera, rc) * tex->size.x);
	while (i < self->win_size.y)
	{
		rc.draw_pos.y = i;
		if (i < cail_end)
			self->pset(self, rc.draw_pos.x, rc.draw_pos.y, rc.ceiling_color);
		if (cail_end <= i && i < wall_end)
			_draw_wall_line(self, rc, tex, tex_pos);
		if (wall_end <= i && i < self->win_size.y)
			self->pset(self, rc.draw_pos.x, rc.draw_pos.y, rc.floor_color);
		i++;
	}
}
