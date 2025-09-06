/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cublx_free_tex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:00:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/05 20:15:25 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"
#include <stdlib.h>

int	_cublx_free_tex(t_cublx *self, t_cublx_img *tex)
{
	if (tex && tex->img)
	{
		mlx_destroy_image(self->mlx, tex->img);
		return (0);
	}
	return (1);
}
