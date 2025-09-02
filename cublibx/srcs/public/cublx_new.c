/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 07:04:18 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/02 10:03:55 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"

static int	_allocate_mlx(t_cublx *cublx)
{
	if (!cublx)
		return (1);
	cublx->mlx = mlx_init();
	if (!cublx->mlx)
		return (1);
	return (0);
}

static int	_allocate_mlx_win(t_cublx *cublx, int w, int h, char *title)
{
	if (!cublx || !cublx->mlx || !title)
		return (1);
	cublx->win = mlx_new_window(cublx->mlx, w, h, title);
	if (!cublx->win)
		return (1);
	return (0);
}

static int	_allocate_cublx_user(t_cublx *cublx)
{
	if (!cublx)
		return (1);
	cublx->user = cublx_calloc(1, sizeof(t_cub_user));
	if (!cublx->user)
		return (1);
	return (0);
}

static int	_allocate_views(t_cublx *cublx, int w, int h)
{
	if (!cublx)
		return (1);
	_allocate_view(&cublx->main_view[0], cublx, w, h);
	_allocate_view(&cublx->main_view[1], cublx, w, h);
	if (!cublx->main_view[0].img || !cublx->main_view[1].img)
		return (1);
	return (0);
}

t_cublx	*cublx_new(int w, int h, char *title)
{
	t_cublx	*cublx;

	cublx = cublx_calloc(1, sizeof(t_cublx));
	if (!cublx)
		return (NULL);
	if (_allocate_mlx(cublx) != 0)
		return (cublx_del(&cublx), NULL);
	if (_allocate_mlx_win(cublx, w, h, title) != 0)
		return (cublx_del(&cublx), NULL);
	if (_allocate_cublx_user(cublx) != 0)
		return (cublx_del(&cublx), NULL);
	if (_allocate_views(cublx, w, h) != 0)
		return (cublx_del(&cublx), NULL);
	cublx->win_size = cublx_vec2i(w, h);
	cublx->btn = _cublx_btn;
	cublx->btnp = _cublx_btnp;
	cublx->pset = _cublx_pset;
	cublx->load_xpm = _cublx_load_xpm;
	cublx->raycasting = _cublx_raycasting;
	cublx->view_switch = 0;
	_cublx_key_state_init(cublx);
	_cublx_key_just_pressed_init(cublx);
	return (cublx);
}
