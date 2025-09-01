/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx_vec2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:00:47 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/01 18:00:47 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx_vec2.h"

t_cublx_vec2	cublx_vec2_zero(void)
{
	return ((t_cublx_vec2){0.0, 0.0});
}

t_cublx_vec2	cublx_vec2_up(void)
{
	return ((t_cublx_vec2){0.0, -1.0});
}

t_cublx_vec2	cublx_vec2_down(void)
{
	return ((t_cublx_vec2){0.0, 1.0});
}

t_cublx_vec2	cublx_vec2_left(void)
{
	return ((t_cublx_vec2){-1.0, 0.0});
}

t_cublx_vec2	cublx_vec2_right(void)
{
	return ((t_cublx_vec2){1.0, 0.0});
}
