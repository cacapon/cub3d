/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:21:15 by yookamot          #+#    #+#             */
/*   Updated: 2025/08/25 15:32:31 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define STEP 0.05

static void	get_distance_to_wall(t_ray *ray)
{
	double	ray_angle;

	//謎に視点が90度ずれていたので荒業で修正している。要注意。
	ray_angle = ((ray->data->player.angle - 90.0) - FOV / 2 + (ray->i
				/ (double)WIDTH) * FOV) * (PI / 180.0);
	ray->dir_x = cos(ray_angle);
	ray->dir_y = sin(ray_angle);
	ray->pos_x = ray->data->player.pos_x;
	ray->pos_y = ray->data->player.pos_y;
	while (1)
	{
		ray->pos_x += ray->dir_x * STEP;
		ray->pos_y += ray->dir_y * STEP;
		if (ray->data->map[(int)ray->pos_y][(int)ray->pos_x] == '1'
			|| ray->data->map[(int)ray->pos_y][(int)ray->pos_x] == '2')
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
	double	wall_height;

	if (FOV == 90)
		projection_plane_distance = WIDTH / 2.0;
	else
		projection_plane_distance = WIDTH / (2.0 * tan(FOV * PI / 180.0));
	ray->wall_height = 1.0 * projection_plane_distance / ray->distance;
	if (ray->wall_height > HEIGHT)
		ray->wall_height = HEIGHT;
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

	ray.data = data;
	ray.i = i;
	get_distance_to_wall(&ray);
	get_wall_height(&ray);
	if (ray.data->map[(int)ray.pos_y][(int)ray.pos_x] == '1')
		get_tex_x(&ray, &data->textures.north);
	else
		get_tex_x(&ray, &data->textures.south);
	draw_ceiling_in_vertical_line(&ray);
	//フラグに応じてどのテクスチャを使うか条件分岐
	if (ray.data->map[(int)ray.pos_y][(int)ray.pos_x] == '1')
		draw_wall_in_vertical_line(&ray, &data->textures.north);
	else
		draw_wall_in_vertical_line(&ray, &data->textures.south);
	draw_floor_in_vertical_line(&ray);
}
