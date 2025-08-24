/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 07:01:45 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/24 16:48:35 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBLX_H
# define CUBLX_H

/*
using std function
	malloc
using type
	size_t
*/
# include "libs/mlx/mlx.h"
# include <X11/keysym.h>
# include <stddef.h>

# define KEY_MAX 0xFFFF

typedef struct s_cublx	t_cublx;

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
	t_cub_user	*user;
	int			_key_state[KEY_MAX];
	int			_key_just_pressed[KEY_MAX];
	int			(*btn)(t_cublx *self, int key_code);
}				t_cublx;

// public
t_cublx	*cublx_new(int w, int h, char *title);
int		cublx_del(t_cublx **cublx);
void	cublx_set_hooks(t_cublx *cublx, int (*update)(t_cublx *),
			int (*draw)(t_cublx *), int (*destructor)(t_cublx *));

// private
void	*_cublx_calloc(size_t count, size_t size);
void	_cublx_key_state_init(t_cublx *self);
void	_cublx_key_just_pressed_init(t_cublx *self);
int		_cublx_key_pressed(int keycode, t_cublx *cublx);
int		_cublx_key_released(int keycode, t_cublx *cublx);
int		_cublx_btn(t_cublx *self, int keycode);
int		_cublx_loop(t_cublx *cublx);
#endif