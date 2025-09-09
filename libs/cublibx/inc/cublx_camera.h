/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx_camera.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:19:18 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/09 16:35:11 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBLX_CAMERA_H
# define CUBLX_CAMERA_H

# include "cublx_vec2.h"
# include "cublx_vec2i.h"
# include "cublx_lib.h"
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_cublx_camera	t_camera;
typedef t_cublx_vec2			t_vec2;
typedef t_cublx_vec2i			t_vec2i;

typedef struct s_cublx_camera
{
	t_vec2	pos;
	t_vec2	dir;
	t_vec2	plane;
	double	fov_deg;

	t_vec2	(*get_ray)(t_camera * self, int x, int w);
	void	(*rotate)(t_camera *self, double angle);
	void	(*move)(t_camera *self, t_vec2 delta, char **map, double margin);
	void	(*set_fov)(t_camera *self, double fov_deg);
	void	(*set_view)(t_camera *self, t_vec2 pos, t_vec2 dir, double fov_deg);
}			t_cublx_camera;

// public
t_camera	*cublx_camera_new(t_vec2 pos, t_vec2 dir, double fov_deg);
int			cublx_camera_del(t_camera **camera);

// methods
t_vec2		_cublx_camera_get_ray(t_camera *self, int x, int w);
void		_cublx_camera_move(
				t_camera *self, t_vec2 delta, char **map, double margin);
void		_cublx_camera_rotate(t_camera *self, double angle);
void		_cublx_camera_set_fov(t_camera *self, double fov_deg);

void	_cublx_camera_set_view(
			t_camera *self, t_vec2 pos, t_vec2 dir, double fov_deg);

#endif