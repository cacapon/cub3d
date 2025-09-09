/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 15:44:28 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/08 23:45:35 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_letter(t_data *data, int fd)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '1' && data->map[i][j] != '0'
				&& data->map[i][j] != ' ' && data->map[i][j] != 'N'
				&& data->map[i][j] != 'E' && data->map[i][j] != 'W'
				&& data->map[i][j] != 'S')
				error_exit(data, fd, "Invalid character in map.");
			j++;
		}
		i++;
	}
}

// TODO angle vector
static void	set_player(t_data *data, int i, int j, char dir)
{
	if (dir == 'N')
		data->player.camera = PI * 3 / 2;
	else if (dir == 'S')
		data->player.angle = PI / 2;
	else if (dir == 'E')
		data->player.angle = 0;
	else if (dir == 'W')
		data->player.angle = PI;
	data->player.pos_x = (double)j + 0.5;
	data->player.pos_y = (double)i + 0.5;
	data->player.dir_x = cos(data->player.angle);
	data->player.dir_y = sin(data->player.angle);
}

static void	check_player(t_data *data, int fd)
{
	int		i;
	int		j;
	bool	player;

	i = 0;
	player = false;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'E'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'S')
			{
				if (player)
					error_exit(data, fd, "Too many player start positions.");
				player = true;
				set_player(data, i, j, data->map[i][j]);
			}
			j++;
		}
		i++;
	}
	if (!player)
		error_exit(data, fd, "No player start position found.");
}

static void	check_map_enclosure(t_data *data, int fd)
{
	int		i;
	int		j;
	char	**m;

	i = 0;
	m = data->map;
	while (m[i])
	{
		j = 0;
		while (m[i][j])
		{
			if (m[i][j] == '0')
			{
				if (i == 0 || !m[i + 1] || j == 0 || m[i - 1][j] == ' ' || m[i
					+ 1][j] == ' ' || m[i][j - 1] == ' ' || m[i][j + 1] == ' ')
					error_exit(data, fd, "Map is not closed by walls.");
			}
			j++;
		}
		i++;
	}
}

void	validate_map(t_data *data, int fd)
{
	check_letter(data, fd);
	check_player(data, fd);
	check_map_enclosure(data, fd);
}
