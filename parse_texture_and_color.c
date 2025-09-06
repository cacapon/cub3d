/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_and_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 14:27:03 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/06 19:59:45 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*skip_space(char *line, t_data *data, int fd)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (!line[i])
		error_exit(data, fd, "Texture path is missing.");
	return (line + i);
}

static int	parse_color(char *line, t_data *data, int fd)
{
	char	**array;
	int		r;
	int		g;
	int		b;
	char	*trimmed;

	trimmed = ft_strtrim(line, "\n");
	if (!trimmed)
		error_exit(data, fd, "Failed to allocate memory.");
	array = ft_split(trimmed, ',');
	free(trimmed);
	if (!array)
		error_exit(data, fd, "Failed to allocate memory.");
	if (!array[0] || !array[1] || !array[2] || array[3])
		error_exit(data, fd, "Invalid RGB format.");
	r = ft_atoi(array[0]);
	g = ft_atoi(array[1]);
	b = ft_atoi(array[2]);
	free_array(array);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || g > 255)
		error_exit(data, fd, "RGB value out of range.");
	return ((r << 16) | (g << 8) | b);
}

static void	set_texture_and_color(t_data *data, char *line, int fd)
{
	if (!ft_strncmp(line, "NO", 2))
		load_xpm(data, &data->textures.north, skip_space(line + 3, data, fd),
			fd);
	else if (!ft_strncmp(line, "SO", 2))
		load_xpm(data, &data->textures.south, skip_space(line + 3, data, fd),
			fd);
	else if (!ft_strncmp(line, "WE", 2))
		load_xpm(data, &data->textures.west, skip_space(line + 3, data, fd),
			fd);
	else if (!ft_strncmp(line, "EA", 2))
		load_xpm(data, &data->textures.east, skip_space(line + 3, data, fd),
			fd);
	else if (!ft_strncmp(line, "F", 1))
		data->floor_color = parse_color(skip_space(line + 2, data, fd), data,
				fd);
	else if (!ft_strncmp(line, "C", 1))
		data->ceiling_color = parse_color(skip_space(line + 2, data, fd), data,
				fd);
	else
		error_exit(data, fd, "Invalid element identifier.");
}

static bool	check_skip_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t'
			&& line[i] != '\r')
			return (false);
		i++;
	}
	return (true);
}

void	parse_texture_and_color(t_data *data, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i < 6)
	{
		line = get_next_line(fd);
		if (!line)
			error_exit(data, fd, "Failed to allocate memory.");
		if (check_skip_line(line))
			continue ;
		set_texture_and_color(data, line, fd);
		free(line);
		i++;
	}
	if (!data->textures.north.img || !data->textures.south.img
		|| !data->textures.east.img || !data->textures.west.img)
		error_exit(data, fd, "Texture not set.");
	if (data->floor_color < 0 || data->ceiling_color < 0)
		error_exit(data, fd, "Color not set.");
}
