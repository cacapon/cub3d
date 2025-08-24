/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 07:00:21 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/24 15:06:31 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"

static int dest(void *param)
{
	return (0);	
}

static int draw(void *param)
{
	return (0);
}

static int update(void *param)
{
	return (0);
}

int	main(void)
{
	t_cublx *cublx;

	cublx = cublx_new(100, 100, "test");
	cublx_set_hooks(cublx, update, draw, dest);
	mlx_loop(cublx->mlx);
	cublx_del(&cublx);
	return (0);
}