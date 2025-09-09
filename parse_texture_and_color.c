/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_and_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 14:27:03 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/09 15:41:56 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_color(char *line, t_cublx *cublx, int fd)
{
	char	**array;
	int		r;
	int		g;
	int		b;
	char	*trimmed;

	trimmed = ft_strtrim(line, "\n");
	if (!trimmed)
		error_exit(cublx, fd, "Failed to allocate memory.");
	array = ft_split(trimmed, ',');
	free(trimmed);
	if (!array)
		error_exit(cublx, fd, "Failed to allocate memory.");
	if (!array[0] || !array[1] || !array[2] || array[3])
		error_exit(cublx, fd, "Invalid RGB format.");
	r = ft_atoi(array[0]);
	g = ft_atoi(array[1]);
	b = ft_atoi(array[2]);
	free_array(array);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || g > 255)
		error_exit(cublx, fd, "RGB value out of range.");
	return ((r << 16) | (g << 8) | b);
}

static void	set_texture_and_color(t_cublx *cublx, char **array, int fd)
{
	t_data	*data;

	data = cublx->user->param;
	if (cub_strcmp(array[0], "NO"))
		cublx->load_xpm(cublx, &data->textures.north, array[1]);
	else if (cub_strcmp(array[0], "SO"))
		cublx->load_xpm(cublx, &data->textures.south, array[1]);
	else if (cub_strcmp(array[0], "WE"))
		cublx->load_xpm(cublx, &data->textures.west, array[1]);
	else if (cub_strcmp(array[0], "EA"))
		cublx->load_xpm(cublx, &data->textures.east, array[1]);
	else if (cub_strcmp(array[0], "F"))
		data->floor_color = parse_color(array[1], cublx, fd);
	else if (cub_strcmp(array[0], "C"))
		data->ceiling_color = parse_color(array[1], cublx, fd);
	else
	{
		free_array(array);
		error_exit(cublx, fd, "Invalid element identifier.");
	}
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
	free(line);
	return (true);
}

void	parse_texture_and_color(t_data *data, t_cublx *cublx, int fd)
{
	int		i;
	char	*line;
	char	**array;

	i = 0;
	while (i < 6)
	{
		line = get_next_line(fd);
		if (!line)
			error_exit(cublx, fd, "Failed to allocate memory.");
		if (check_skip_line(line))
			continue ;
		array = ft_split(line, ' ');
		free(line);
		if (!array)
			error_exit(cublx, fd, "Failed to allocate memory.");
		set_texture_and_color(cublx, array, fd);
		free_array(array);
		i++;
	}
	if (!data->textures.north.img || !data->textures.south.img
		|| !data->textures.east.img || !data->textures.west.img)
		error_exit(cublx, fd, "Texture not set.");
	if (data->floor_color < 0 || data->ceiling_color < 0)
		error_exit(cublx, fd, "Color not set.");
}
