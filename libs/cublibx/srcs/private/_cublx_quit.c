/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cublx_quit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:02:48 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/02 11:15:06 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"
#include <stdlib.h>

int	_cublx_quit(t_cublx *self, int stscode)
{
	cublx_del(&self);
	exit(stscode);
	return (0);
}
