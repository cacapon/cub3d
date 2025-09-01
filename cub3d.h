/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:27:52 by yookamot          #+#    #+#             */
/*   Updated: 2025/08/30 20:58:56 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define FOV 90
# define WIDTH 1048
# define HEIGHT 768
# define PI 3.14159265358979323846
# define STEP 0.007
# define FRONT 0
# define BACK 1
# define LEFT 2
# define RIGHT 3

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_textures
{
	t_img		north;
	t_img		south;
	t_img		east;
	t_img		west;
}				t_textures;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		move_speed;
	double		rot_speed;
	int			move_forward;
	int			move_backward;
	int			strafe_left;
	int			strafe_right;
	int			turn_left;
	int			turn_right;
	double		angle;
}				t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_textures	textures;
	int			floor_color;
	int			ceiling_color;
	t_img		front_buffer;
	t_img		back_buffer;
	int			current_buffer;
	char		**map;
	t_player	player;
}				t_data;

typedef struct s_ray
{
	int			i;
	double		angle;
	double		dir_x;
	double		dir_y;
	double		pos_x;
	double		pos_y;
	double		distance;
	double		wall_height;
	int			hit_wall;
	t_data		*data;
	int			tex_x;
	int			tex_y;
	double		tex_pos;
}				t_ray;

void			read_map(t_data *data);
void			free_array(char **array);
void			init_game(t_data *data);
void			load_all_textures(t_data *data);
int				game_loop(t_data *data);
int				destroy_window(t_data *data);
void			exit_game(t_data *data, int status);
int				key_press(int keycode, t_data *data);
int				key_release(int keycode, t_data *data);
void			ray_casting(t_data *data, int i);
void			draw_ceiling_in_vertical_line(t_ray *ray);
void			draw_wall_in_vertical_line(t_ray *ray, t_img *img);
void			draw_floor_in_vertical_line(t_ray *ray);

#endif