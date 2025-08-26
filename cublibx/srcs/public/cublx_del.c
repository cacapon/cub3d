/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 07:11:21 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/26 10:17:37 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"
#include <stdlib.h>

static void	_free_cublx_user(t_cub_user **user)
{
	if (!user || !*user)
		return ;
	free(*user);
	*user = NULL;
}

static void	_free_mlx_win(void *mlx, void **win)
{
	if (!mlx || !win || !*win)
		return ;
	mlx_destroy_window(mlx, *win);
	*win = NULL;
}

static void	_free_mlx(void **mlx)
{
	if (!mlx || !*mlx)
		return ;
	mlx_destroy_display(*mlx);
	free(*mlx);
	*mlx = NULL;
}

static void	_free_view(void *mlx, t_cublx_img *view)
{
	if (!view)
		return ;
	if (view->img)
	{
		mlx_destroy_image(mlx, view->img);
		view->img = NULL;
	}
	view->addr = NULL;
}

/**
 * @brief Delete the cublx instance.
 *
 * @param culbx
 * @return int
 */
int	cublx_del(t_cublx **culbx)
{
	t_cublx	*_cublx;

	if (!culbx || !*culbx)
		return (1);
	_cublx = *culbx;
	if (_cublx->user && _cublx->user->destructor)
		_cublx->user->destructor(_cublx);
	_free_cublx_user(&_cublx->user);
	_free_view(_cublx->mlx, &_cublx->main_v.view[0]);
	_free_view(_cublx->mlx, &_cublx->main_v.view[1]);
	_free_mlx_win(_cublx->mlx, &_cublx->win);
	_free_mlx(&_cublx->mlx);
	free(_cublx);
	*culbx = NULL;
	return (0);
}
