/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx_vec2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:52:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/01 17:57:27 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBLX_VEC2_H
# define CUBLX_VEC2_H

typedef struct s_cublx_vec2
{
	double		x;
	double		y;
}				t_cublx_vec2;

t_cublx_vec2	cublx_vec2_zero(void);
t_cublx_vec2	cublx_vec2_up(void);
t_cublx_vec2	cublx_vec2_down(void);
t_cublx_vec2	cublx_vec2_left(void);
t_cublx_vec2	cublx_vec2_right(void);

#endif