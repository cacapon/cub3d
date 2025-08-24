/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 07:00:21 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/24 17:36:06 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Destructor for erasing user-defined dynamic allocation data.
 *
 * @param cublx
 * @return int
 */
static int	dest(t_cublx *cublx)
{
	return (0);
}

static int	draw(t_cublx *cublx)
{
	return (0);
}

static int	update(t_cublx *cublx)
{
	if (cublx->btnp(cublx, XK_q))
	{
		printf("push q btn\n");
		cublx_del(&cublx);
		exit(0);
	}
	if (cublx->btn(cublx, XK_a))
		printf("pressing a btn\n");
	return (0);
}

int	main(void)
{
	t_cublx	*cublx;
	void	*param;

	param = NULL;
	cublx = cublx_new(100, 100, "test");
	cublx_set_hooks(cublx, update, draw, dest);
	cublx_set_user_param(cublx, param);
	cublx_run(cublx);
	cublx_del(&cublx);
	return (0);
}
