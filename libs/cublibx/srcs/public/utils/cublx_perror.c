/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx_perror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 07:58:37 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/22 08:33:51 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"
#include <stdio.h>

void	cublx_perror(int errcode)
{
	static char	*err_str[] = {
		ERR_CUBLX_000, ERR_CUBLX_001,
	};

	printf("Error\n");
	if (0 <= errcode && errcode < E_CUBLX_XXX)
		printf("%s\n", err_str[errcode]);
	else
		printf("%s\n", err_str[E_CUBLX_XXX]);
}
