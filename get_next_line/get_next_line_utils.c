/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:42:03 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/06 18:55:57 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin_gnl(char *left_str, char *buff)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!left_str)
	{
		left_str = (char *)malloc(1);
		if (!left_str)
			return (NULL);
		left_str[0] = '\0';
	}
	if (!buff)
		return (NULL);
	str = (char *)malloc(ft_strlen(left_str) + ft_strlen(buff) + 1);
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (left_str[++i])
		str[i] = left_str[i];
	while (buff[j])
		str[i++] = buff[j++];
	str[i] = '\0';
	free(left_str);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		len = 0;
	if (len > s_len - start)
		len = s_len - start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (j < len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
