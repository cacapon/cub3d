/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:46:39 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/05 19:24:41 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
void	draw_ceiling_in_vertical_line(t_ray *ray)
{
	int	start;
	int	end;
	int	*dst;
	int	y;

	start = 0;
	end = (int)((HEIGHT - ray->wall_height) / 2);
	if (end < 0)
		end = 0;
	dst = (int *)ray->data->front_buffer.addr;
	y = 0;
	while (y < end)
	{
		dst[y * WIDTH + ray->i] = ray->data->ceiling_color;
		y++;
	}
}

void	draw_wall_in_vertical_line(t_ray *ray, t_img *img)
{
	double	step;
	int		y;
	int		end;
	int		*dst;

	step = (double)img->size.y / ray->wall_height;
	ray->tex_pos = 0.0;
	y = (HEIGHT - ray->wall_height) / 2;
	if (y < 0)
		y = 0;
	end = (HEIGHT + ray->wall_height) / 2;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	dst = (int *)ray->data->front_buffer.addr;
	ray->tex_y = 0;
	while (y <= end)
	{
		ray->tex_y = (int)ray->tex_pos;
		if (ray->tex_y >= img->size.y)
			ray->tex_y = img->size.y - 1;
		dst[y * WIDTH + ray->i] = ((int *)img->addr)[ray->tex_y * img->size.x
			+ ray->tex_x];
		ray->tex_pos += step;
		y++;
	}
}

void	draw_floor_in_vertical_line(t_ray *ray)
{
	int	start;
	int	end;
	int	*dst;
	int	y;

	start = (int)((HEIGHT + ray->wall_height) / 2);
	end = HEIGHT - 1;
	if (start < 0)
		start = 0;
	if (start >= HEIGHT)
		return ;
	dst = (int *)ray->data->front_buffer.addr;
	y = start;
	while (y <= end)
	{
		dst[y * WIDTH + ray->i] = ray->data->floor_color;
		y++;
	}
}
*/
