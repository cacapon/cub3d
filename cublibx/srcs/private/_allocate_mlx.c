/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _allocate_cublx copy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 06:43:37 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/24 06:44:14 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"

int _allocate_mlx(t_cublx *cublx)
{
	if (!cublx)
		return (1);
	cublx->mlx = mlx_init();
	if (!cublx->mlx)
		return (1);
	return (0);
}
