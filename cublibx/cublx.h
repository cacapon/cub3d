/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 07:01:45 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/22 19:45:09 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBLX_H
# define CUBLX_H

// using std function
// malloc

// include size_t
# include <stddef.h>

typedef struct s_cublx
{
	/* data */
}		t_cublx;

// public
t_cublx	*cublx_new(void);
int		cublx_del(t_cublx **cublx);

// private
void	*_cublx_calloc(size_t count, size_t size);

#endif