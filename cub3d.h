/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:27:52 by yookamot          #+#    #+#             */
/*   Updated: 2025/08/19 15:45:54 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// WIN_(H/W) is a provisional value.
# define WIN_H 480
# define WIN_W 640
# define TITLE_NAME "Cub3D"

# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_vector2
{
	double		x;
	double		y;
}				t_vector2;

typedef struct s_vector2i
{
	int			x;
	int			y;
}				t_vector2i;

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
	t_vector2	pos;
	t_vector2	dir;
	t_vector2	plane;
}				t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_vector2i	win_size;
	t_textures	textures;
	int			floor_color;
	int			ceiling_color;
	t_img		front_buffer;
	t_img		back_buffer;
	int			current_buffer;
	char		**map;
	t_player	player;
}				t_data;

t_data	*cub3d_init(void);

#endif