/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:27:52 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/16 17:28:02 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cublx.h"
# include "get_next_line/get_next_line.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define FOV 66
# define WIDTH 1048
# define HEIGHT 768
# define PI 3.14159265358979323846

typedef struct s_textures
{
	t_img		north;
	t_img		south;
	t_img		east;
	t_img		west;
}				t_textures;

typedef struct s_player
{
	t_camera	*camera;
	double		move_speed;
	double		rot_speed;
}				t_player;

typedef struct s_data
{
	t_textures	textures;
	int			floor_color;
	int			ceiling_color;
	char		**map;
	t_player	player;
}				t_data;

bool			cub_strcmp(const char *s1, const char *s2);
char			**ft_split(char const *s, char c);
int				ft_atoi(const char *str);
char			*ft_strdup(const char *src);
char			*ft_strtrim(const char *s1, const char *set);
char			*ft_strjoin(const char *str1, const char *str2);
void			parse_cub_file(t_cublx *cublx, char *file);
void			parse_texture_and_color(t_data *data, t_cublx *cublx, int fd);
void			parse_map(t_cublx *cublx, int fd);
void			validate_map(t_cublx *cublx, int fd);
void			draw_minimap(t_cublx *cublx);
void			free_array(char **array);
void			init_game(t_data *data);
int				game_loop(t_cublx *cublx);
int				draw_buffer(t_cublx *cublx);
void			error_exit(t_cublx *cublx, int fd, char *msg);
int				ft_count_char(char *str, char c);

#endif