/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:27:52 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/07 20:21:31 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line/get_next_line.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
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

void			free_array(char **array);
void			init_game(t_data *data);
int				game_loop(t_data *data);
int				destroy_window(t_data *data);
void			exit_game(t_data *data, int status);
int				key_press(int keycode, t_data *data);
int				key_release(int keycode, t_data *data);
void			ray_casting(t_data *data, int i);
void			draw_ceiling_in_vertical_line(t_ray *ray);
void			draw_wall_in_vertical_line(t_ray *ray, t_img *img);
void			draw_floor_in_vertical_line(t_ray *ray);
void			move_player(t_data *data, double dir_x, double dir_y);
char			**ft_split(char const *s, char c);
bool			cub_strcmp(const char *s1, const char *s2);
int				ft_atoi(const char *str);
char			*ft_strdup(const char *src);
char			*ft_strtrim(const char *s1, const char *set);
char			*ft_strjoin(const char *str1, const char *str2);
void			parse_cub_file(t_data *data, char *file);
void			parse_texture_and_color(t_data *data, int fd);
void			parse_map(t_data *data, int fd);
void			validate_map(t_data *data, int fd);
void			load_xpm(t_data *data, t_img *img, char *path, int fd);
void			error_exit(t_data *data, int fd, char *msg);
void			draw_minimap(t_data *data);

#endif