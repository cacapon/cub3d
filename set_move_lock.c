/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_move_lock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:29:03 by yookamot          #+#    #+#             */
/*   Updated: 2025/08/26 22:08:22 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	set_move_lock(t_ray *ray, double projection_plane_distance)
{
	double	stop_distance;
	int		direction;

	stop_distance = 1.0 * projection_plane_distance / HEIGHT;
	get_colligion_direction(ray);
	if (ray->distance > stop_distance)
		return ;
	if (ray->hit_wall == FRONT)
		ray->data->front_lock = 1;
	if (ray->hit_wall == BACK)
		ray->data->back_lock = 1;
	if (ray->hit_wall == LEFT)
		ray->data->left_lock = 1;
	if (ray->hit_wall == RIGHT)
		ray->data->right_lock = 1;
}
