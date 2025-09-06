/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:51:27 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/06 18:56:26 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2 || n == 0)
		return (0);
	if (s1[0] == '\0')
		return ((unsigned char)*s1 - (unsigned char)*s2);
	while (i < n)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

char	*ft_strdup(const char *src)
{
	int		len;
	int		i;
	char	*array;

	if (!src)
		return (NULL);
	i = 0;
	len = (int)ft_strlen(src);
	array = (char *)malloc((len + 1) * sizeof(char));
	if (!array)
		return (NULL);
	while (src[i] != '\0')
	{
		array[i] = src[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!str1 || !str2)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!str)
		return (NULL);
	while (str1[i])
		str[j++] = str1[i++];
	i = 0;
	while (str2[i])
		str[j++] = str2[i++];
	str[j] = '\0';
	return (str);
}
