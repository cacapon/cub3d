/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cublx_pset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 20:52:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/25 18:54:31 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"

int	_cublx_pset(t_cublx *self, int x, int y, int color)
{
	char		*dst;
	t_cublx_img	view;

	view = self->main_view[self->view_switch];
	dst = view.addr + (y * view.line_length + x * (view.bits_per_pixel / 8));
	*(unsigned int *)dst = (unsigned int)color;
	return (0);
}
