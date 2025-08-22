/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 07:11:21 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/22 20:50:18 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"
#include <stdlib.h>

int	cublx_del(t_cublx **culbx)
{
	t_cublx	*_cublx;

	if (!culbx || !*culbx)
		return (1);
	_cublx = *culbx;
	if (_cublx->win)
		mlx_destroy_window(_cublx->mlx, _cublx->win);
	if (_cublx->mlx)
	{
		mlx_destroy_display(_cublx->mlx);
		free(_cublx->mlx);
	}
	free(_cublx);
	*culbx = NULL;
	return (0);
}
