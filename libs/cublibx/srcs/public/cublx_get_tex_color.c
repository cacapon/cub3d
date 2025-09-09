/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx_get_tex_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:08:01 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/05 19:15:50 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"

/**
 * @brief
 *
 * @param tex
 * @param x
 * @param y
 * @return int: color (0xRRGGBBAA)
 * @note tex->addr: Beginning of the image address.
 * @note tex->addr + (y * tex->line_length): Address at the beginning of y row.
 * @note x * (bits_per_pixel / 8): bytes per pixel.
 * @note e.g. 32bit -> 4byte 24bit -> 3byte
 * @note *(unsigned int *)dst: Since uint is 4 bytes,
 * the RGBA information at the specified address is picked up.
 */
int	cublx_get_tex_color(t_cublx_img tex, int x, int y)
{
	char	*dst;

	dst = tex.addr + (y * tex.line_length + x * (tex.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
