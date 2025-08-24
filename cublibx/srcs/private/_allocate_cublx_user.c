/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _allocate_cublx_user.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 06:43:37 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/24 06:46:17 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"

int _allocate_cublx_user(t_cublx *cublx)
{
	if (!cublx)
		return (1);
	cublx->user = _cublx_calloc(1, sizeof(t_cub_user));
	if (!cublx->user)
		return (1);
	return (0);
}
