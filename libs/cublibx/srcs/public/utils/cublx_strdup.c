/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx_strdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:47:04 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/09 15:52:33 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"

char	*cublx_strdup(const char *s1)
{
	size_t	l;
	char	*d;

	if (!s1)
		return (NULL);
	l = (size_t)cublx_strlen((char *)s1);
	d = cublx_calloc(l + 1, sizeof(char));
	if (!d)
		return (NULL);
	return ((char *)cublx_memcpy(d, s1, l + 1));
}
