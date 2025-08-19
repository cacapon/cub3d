/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:23:48 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/19 18:50:31 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief
 *
 * @param data
 * @note TODO: We assume that obj exists at x=0, y=10.
 *
 * Normally, we would examine the map carefully.
 */
static int	execute(t_data *data)
{
	t_vector2i	grid_pos;
	t_vector2i	step;
	t_vector2	ray_dir;
	t_vector2	delta_dist;
	t_vector2	side_dist;
	double		camera_x;
	double		perp_wall_dist;
	int			x;
	int			y;
	int			hit;
	int			side;
	int			line_h;
	int			draw_start;
	int			draw_end;
	int			max_dist = 50;	// DEBUG
	int			traveled;	// DEBUG
	void		*mlx;
	void		*win;
	t_size2i	win_size;
	t_player	player;

	mlx = data->mlx;
	win = data->win;
	win_size = data->win_size;
	player = data->player;
	x = 0;
	step = (t_vector2i){.x = 0, .y = 0};
	while (x < win_size.w)
	{
		camera_x = 2 * x / (double)win_size.w - 1;
		ray_dir.x = player.dir.x + player.plane.x * camera_x;
		ray_dir.y = player.dir.y + player.plane.y * camera_x;
		grid_pos.x = (int)player.pos.x;
		grid_pos.y = (int)player.pos.y;
		delta_dist.x = fabs(1 / ray_dir.x);
		delta_dist.y = fabs(1 / ray_dir.y);
		if (ray_dir.x < 0)
		{
			step.x = -1;
			side_dist.x = (player.pos.x - grid_pos.x) * delta_dist.x;
		}
		else
		{
			step.x = 1;
			side_dist.x = (grid_pos.x + 1.0 - player.pos.x) * delta_dist.x;
		}
		if (ray_dir.y < 0)
		{
			step.y = -1;
			side_dist.y = (player.pos.y - grid_pos.y) * delta_dist.y;
		}
		else
		{
			step.y = 1;
			side_dist.y = (grid_pos.y + 1.0 - player.pos.y) * delta_dist.y;
		}
		hit = 0;
		traveled = 0;
		while (hit == 0 && traveled < max_dist)
		{
			if (side_dist.x < side_dist.y)
			{
				side_dist.x += delta_dist.x;
				grid_pos.x += step.x;
				side = HIT_XLINE;
			}
			else
			{
				side_dist.y += delta_dist.y;
				grid_pos.y += step.y;
				side = HIT_YLINE;
			}
			if (grid_pos.x == 0 && grid_pos.y == -10)
				hit = 1;
			traveled++;
		}
		if (hit == 0)
		{
			x++;
			continue;
		}
		if (side == HIT_XLINE)
			perp_wall_dist = (grid_pos.x - player.pos.x + (1 - step.x) / 2)
				/ ray_dir.x;
		else
			perp_wall_dist = (grid_pos.y - player.pos.y + (1 - step.y) / 2)
				/ ray_dir.y;
		line_h = (int)(win_size.h / perp_wall_dist);
		draw_start = -line_h / 2 + win_size.h / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_h / 2 + win_size.h / 2;
		if (draw_end >= win_size.h)
			draw_end = win_size.h - 1;
		y = draw_start;
		while (y <= draw_end)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
			y++;
		}
		x++;
		
	}
	
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	(void)argc;
	(void)argv;
	data = cub3d_init();
	printf("DBG: pos=(%f,%f)\n", data->player.pos.x, data->player.pos.y);
	printf("DBG: p_dir=(%f,%f)\n", data->player.dir.x, data->player.dir.y);
	mlx_loop_hook(data->mlx, execute, data);
	mlx_loop(data->mlx);
	return (0);
}
