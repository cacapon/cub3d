/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx_strtrim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:45:07 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/09 16:02:34 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx.h"

char	*cublx_strtrim(char const *s1, char const *set)
{
	size_t	st;
	size_t	ed;
	char	*trim_str;

	if (s1 == NULL || *s1 == '\0')
		return (cublx_strdup(""));
	if (set == NULL || *set == '\0')
		return (cublx_strdup(s1));
	st = 0;
	ed = cublx_strlen((char *)s1) - 1;
	while (st <= ed && cublx_strchr(set, s1[st]) != NULL)
		st++;
	while (ed >= st && cublx_strchr(set, s1[ed]) != NULL)
		ed--;
	trim_str = cublx_calloc(ed - st + 2, sizeof(char));
	if (trim_str == NULL)
		return (NULL);
	cublx_strlcpy(trim_str, s1 + st, ed - st + 2);
	return (trim_str);
}