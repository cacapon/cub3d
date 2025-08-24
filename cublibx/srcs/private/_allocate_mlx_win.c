/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _allocate_mlx_win.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 06:43:37 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/24 06:45:05 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"

int _allocate_mlx_win(t_cublx *cublx, int w, int h, char *title)
{
	if (!cublx || !cublx->mlx || !title)
		return (1);
	cublx->win = mlx_new_window(cublx->mlx, w, h, title);
	if (!cublx->win)
		return (1);
	return (0);
}
