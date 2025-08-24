/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 07:00:21 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/24 15:20:21 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"
#include <stdio.h>
#include <stdlib.h>

static int dest(t_cublx *cublx)
{
	return (0);	
}

static int draw(t_cublx *cublx)
{
	return (0);
}

static int update(t_cublx *cublx)
{
	if (cublx->btn(cublx, XK_q))
	{
		printf("push q btn\n");
		cublx_del(&cublx);
		exit(0);
	}
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