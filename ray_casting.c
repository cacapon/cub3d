/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:21:15 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/01 20:08:00 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define FOV_RAD FOV *PI / 180.0

static void	get_distance_to_wall(t_ray *ray)
{
	double	camera_offset;

	camera_offset = ((double)ray->i / WIDTH - 0.5) * FOV_RAD;
	ray->angle = ray->data->player.angle + camera_offset;
	ray->dir_x = cos(ray->angle);
	ray->dir_y = sin(ray->angle);
	ray->pos_x = ray->data->player.pos_x;
	ray->pos_y = ray->data->player.pos_y;
	while (1)
	{
		ray->pos_x += ray->dir_x * STEP;
		ray->pos_y += ray->dir_y * STEP;
		if (ray->data->map[(int)ray->pos_y][(int)ray->pos_x] == '1')
			break ;
	}
	ray->distance = sqrt((ray->pos_x - ray->data->player.pos_x) * (ray->pos_x
				- ray->data->player.pos_x) + (ray->pos_y
				- ray->data->player.pos_y) * (ray->pos_y
				- ray->data->player.pos_y));
}

static void	get_wall_height(t_ray *ray)
{
	double	projection_plane_distance;

	if (FOV == 90)
		projection_plane_distance = WIDTH / 2.0;
	else
		projection_plane_distance = WIDTH / (2.0 * tan(FOV * PI / 180.0));
	ray->wall_height = 1.0 * projection_plane_distance / ray->distance;
}

static void	get_colligion_direction(t_ray *ray)
{
	double	prev_x;
	double	prev_y;

	prev_x = ray->pos_x - ray->dir_x * STEP;
	prev_y = ray->pos_y - ray->dir_y * STEP;
	if ((int)prev_x != (int)ray->pos_x)
	{
		if (ray->pos_x > prev_x)
			ray->hit_wall = RIGHT;
		else
			ray->hit_wall = LEFT;
	}
	else if ((int)prev_y != (int)ray->pos_y)
	{
		if (ray->pos_y < prev_y)
			ray->hit_wall = FRONT;
		else
			ray->hit_wall = BACK;
	}
	else
		ray->hit_wall = -1;
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
		if (ray->pos_x < prev_x)
			wall_x = 1.0 - wall_x;
		hit_vertical = 1;
	}
	else
	{
		wall_x = ray->pos_x - floor(ray->pos_x);
		hit_vertical = 0;
	}
	//ここで東西南北のテクスチャの条件分岐（テクスチャのサイズが同じならば必要ない）
	//東西南北どの面にあたったかの判定をし、適切なフラグをray構造体内でたてる
	ray->tex_x = (int)(wall_x * img->width);
}

void	ray_casting(t_data *data, int i)
{
	t_ray	ray;
	t_img	*tex_img;

	ray.data = data;
	ray.i = i;
	get_distance_to_wall(&ray);
	get_wall_height(&ray);
	get_colligion_direction(&ray);
	if (ray.hit_wall == FRONT)
		tex_img = &data->textures.south;
	else if (ray.hit_wall == BACK)
		tex_img = &data->textures.north;
	else if (ray.hit_wall == LEFT)
		tex_img = &data->textures.east;
	else if (ray.hit_wall == RIGHT)
		tex_img = &data->textures.west;
	get_tex_x(&ray, tex_img);
	draw_ceiling_in_vertical_line(&ray);
	draw_wall_in_vertical_line(&ray, tex_img);
	draw_floor_in_vertical_line(&ray);
}
