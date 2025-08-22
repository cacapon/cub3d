/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 07:11:21 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/20 07:15:10 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"
#include <stdlib.h>

int cublx_del(t_cublx **culbx)
{
	t_cublx	*_cublx;

	if (!culbx || !*culbx)
		return (1);
	_cublx = *culbx;
	free(_cublx);
	*culbx = NULL;	
	return (0);
}
