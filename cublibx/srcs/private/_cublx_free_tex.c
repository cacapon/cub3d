/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cublx_free_tex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:00:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/02 17:13:45 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"
#include <stdlib.h>

int	_cublx_free_tex(t_cublx *self, t_cublx_img **tex)
{
	t_cublx_img	*_tex;

	_tex = *tex;
	if (_tex && _tex->img)
	{
		mlx_destroy_image(self->mlx, _tex);
		free(_tex);
		*tex = NULL;
		return (0);
	}
	return (1);
}
