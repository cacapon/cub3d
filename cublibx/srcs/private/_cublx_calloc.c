/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cublx_calloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 07:04:18 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/20 07:18:33 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

static void	*_cublx_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	if (!b)
		return (b);
	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
		ptr[i++] = (unsigned char)c;
	return (b);
}

void	*_cublx_calloc(size_t count, size_t size)
{
	void	*_block;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (size > SIZE_MAX / count)
		return (NULL);
	_block = malloc(count * size);
	if (!_block)
		return (NULL);
	_cublx_memset(_block, 0, count * size);
	return (_block);
}
