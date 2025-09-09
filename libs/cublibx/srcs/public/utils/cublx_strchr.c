/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx_strchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:47:00 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/09 15:49:40 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"

char	*cublx_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	return (cublx_memchr(s, c, cublx_strlen(s) + 1));
}
