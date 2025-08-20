/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:21:15 by yookamot          #+#    #+#             */
/*   Updated: 2025/08/20 21:40:09 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define STEP 0.05

static void	get_distance_to_wall(t_ray *ray)
{
	double	ray_angle;

	ray_angle = ray->data->player.angle - FOV / 2 + (ray->i / (double)WIDTH)
		* FOV;
	ray->dir_x = cos(ray_angle);
	ray->dir_y = sin(ray_angle);
	ray->pos_x = ray->data->player.pos_x;
	ray->pos_y = ray->data->player.pos_y;
	while (1)
	{
		if (ray->data->map[(int)ray->pos_y][(int)ray->pos_x] == '1')
			break ;
		ray->pos_x += ray->dir_x * STEP;
		ray->pos_y += ray->dir_y * STEP;
	}
	ray->distance = sqrt((ray->pos_x - ray->data->player.pos_x) * (ray->pos_x
				- ray->data->player.pos_x) + (ray->pos_y
				- ray->data->player.pos_y) * (ray->pos_y
				- ray->data->player.pos_y));
}

static double	get_wall_height(t_ray *ray)
{
	double	projection_plane_distance;
	double	wall_height;

	projection_plane_distance = (WIDTH / 2) / tan(FOV / 2);
	ray->wall_height = (TILE_SIZE / ray->distance) * projection_plane_distance;
}

static void	get_tex_x(t_ray *ray, t_img *img)
{
	double	prev_x;
	double	prev_y;
	double	wall_x;
	int		hit_vertical;

	prev_x = ray->pos_x - ray->dir_x * STEP;
	prev_y = ray->pos_y - ray->dir_y * STEP;
	if ((int)prev_x != (int)ray->pos_x)
	{
		wall_x = ray->pos_y - floor(ray->pos_y);
		hit_vertical = 1;
	}
	else
	{
		wall_x = ray->pos_x - floor(ray->pos_x);
		hit_vertical = 0;
	}
	ray->tex_x = (int)(wall_x * img->width);
	if (hit_vertical && ray->dir_x > 0)
		ray->tex_x = img->width - ray->tex_x - 1;
	if (!hit_vertical && ray->dir_y > 0)
		ray->tex_x = img->width - ray->tex_x - 1;
}

void	ray_casting(t_data *data, int i)
{
	t_ray	ray;

	ray.data = data;
	ray.i = i;
	get_distance_to_wall(&ray);
	get_wall_height(&ray);
	get_tex_x(&ray, &data->textures.north);
	draw_ceiling_in_vertical_line(&ray);
	draw_wall_in_vertical_line(&ray, &data->textures.north);
	draw_floor_in_vertical_line(&ray);
}
