/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx_vec2i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:00:55 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/01 18:01:43 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx_vec2i.h"

t_cublx_vec2i	cublx_vec2i_zero(void)
{
	return ((t_cublx_vec2i){0, 0});
}

t_cublx_vec2i	cublx_vec2i_up(void)
{
	return ((t_cublx_vec2i){0, -1});
}

t_cublx_vec2i	cublx_vec2i_down(void)
{
	return ((t_cublx_vec2i){0, 1});
}

t_cublx_vec2i	cublx_vec2i_left(void)
{
	return ((t_cublx_vec2i){-1, 0});
}

t_cublx_vec2i	cublx_vec2i_right(void)
{
	return ((t_cublx_vec2i){1, 0});
}
