/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 14:27:55 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/09 17:40:50 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	read_map(t_cublx *cublx, int fd)
{
	t_data	*data;
	char	*line;
	char	*map_line;

	data = cublx->user->param;
	line = get_next_line(fd);
	map_line = NULL;
	while (line)
	{
		map_line = ft_strjoin_gnl(map_line, line);
		if (!map_line)
			error_exit(cublx, fd, "Failed to allocate memory.");
		free(line);
		line = get_next_line(fd);
	}
	data->map = ft_split(map_line, '\n');
	free(map_line);
	if (!data->map)
		error_exit(cublx, fd, "Failed to allocate memory.");
}

static char	*add_space(char *line, int len, int max_width)
{
	char	*new;
	int		i;

	if (len == max_width)
		return (line);
	new = (char *)malloc(sizeof(char) * (max_width + 1));
	if (!new)
		return (free(line), NULL);
	i = 0;
	while (i < max_width)
	{
		if (i < len)
			new[i] = line[i];
		else
			new[i] = ' ';
		i++;
	}
	new[i] = '\0';
	free(line);
	return (new);
}

static void	reshape_map(t_cublx *cublx, int fd)
{
	int		i;
	int		len;
	int		max_width;
	t_data	*data;

	i = 0;
	max_width = 0;
	data = cublx->user->param;
	while (data->map[i])
	{
		len = ft_strlen(data->map[i]);
		if (len > max_width)
			max_width = len;
		i++;
	}
	i = 0;
	while (data->map[i])
	{
		len = ft_strlen(data->map[i]);
		data->map[i] = add_space(data->map[i], len, max_width);
		if (!data->map[i])
			error_exit(cublx, fd, "Failed to allocate memory.");
		i++;
	}
}

void	parse_map(t_cublx *cublx, int fd)
{
	read_map(cublx, fd);
	reshape_map(cublx, fd);
	validate_map(cublx, fd);
}
