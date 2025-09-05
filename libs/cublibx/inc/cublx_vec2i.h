/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx_vec2i.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:52:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/02 09:56:09 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBLX_VEC2I_H
# define CUBLX_VEC2I_H

typedef struct s_cublx_vec2i
{
	int			x;
	int			y;
}				t_cublx_vec2i;

t_cublx_vec2i	cublx_vec2i(int x, int y);

#endif