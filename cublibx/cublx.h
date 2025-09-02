/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 07:01:45 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/02 09:28:18 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBLX_H
# define CUBLX_H

# include "libs/mlx/mlx.h"
# include "inc/cublx_lib.h"
# include "inc/cublx_vec2.h"
# include "inc/cublx_vec2i.h"
# include "inc/cublx_camera.h"
# include <X11/keysym.h>

# define KEY_MAX 0xFFFF
# define HIT_XLINE 0
# define HIT_YLINE 1

typedef struct s_cublx	t_cublx;
typedef t_cublx_vec2i	t_vec2i;

typedef struct s_raycasting
{
	int		x;
	char	**map;
	int		ceiling_color;
	int		floor_color;
	int		wall_color;
	t_vec2i	grid_pos;
	t_vec2i	step;
	t_vec2	ray_dir;
	t_vec2	delta_dist;
	t_vec2	side_dist;
	int		line_h;
	double	perp_wall_dist;
}			t_raycasting;

typedef struct s_cublx_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_vec2i		size;
}				t_cublx_img;

typedef struct s_cub_user
{
	int			(*update)(t_cublx *);
	int			(*draw)(t_cublx *);
	int			(*destructor)(t_cublx *);
	void		*param;
}				t_cub_user;

typedef struct s_cublx
{
	void		*mlx;
	void		*win;
	t_vec2		win_size;
	t_cublx_img	main_view[2];
	t_cub_user	*user;
	int			view_switch;
	int			_key_state[KEY_MAX];
	int			_key_just_pressed[KEY_MAX];
	int			(*pset)(t_cublx *self, int x, int y, int color);
	int			(*btn)(t_cublx *self, int key_code);
	int			(*btnp)(t_cublx *self, int key_code);
	int			(*load_xpm)(t_cublx *self, t_cublx_img *img, char *xpm_path);
	int			(*raycasting)(t_cublx *self, t_camera *camera, t_raycasting rc);
}				t_cublx;

// public
t_cublx	*cublx_new(int w, int h, char *title);
int		cublx_del(t_cublx **cublx);
void	cublx_set_hooks(t_cublx *cublx, int (*update)(t_cublx *),
			int (*draw)(t_cublx *), int (*destructor)(t_cublx *));
void	cublx_set_user_param(t_cublx *cublx, void *user_param);
void	cublx_run(t_cublx *cublx);

// private
int		_allocate_view(t_cublx_img *view, t_cublx *cublx, int w, int h);
void	_cublx_key_state_init(t_cublx *self);
void	_cublx_key_just_pressed_init(t_cublx *self);
int		_cublx_key_pressed(int keycode, t_cublx *cublx);
int		_cublx_key_released(int keycode, t_cublx *cublx);
int		_cublx_pset(t_cublx *self, int x, int y, int color);
int		_cublx_btn(t_cublx *self, int keycode);
int		_cublx_btnp(t_cublx *self, int keycode);
int		_cublx_loop(t_cublx *cublx);
int		_cublx_load_xpm(t_cublx *self, t_cublx_img *img, char *xpm_path);
int		_cublx_raycasting(t_cublx *self, t_camera *camera, t_raycasting rc);

#endif