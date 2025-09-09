/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 15:44:28 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/09 15:22:28 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_letter(t_cublx *cublx, int fd)
{
	int		i;
	int		j;
	t_data	*data;

	i = 0;
	data = cublx->user->param;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '1' && data->map[i][j] != '0'
				&& data->map[i][j] != ' ' && data->map[i][j] != 'N'
				&& data->map[i][j] != 'E' && data->map[i][j] != 'W'
				&& data->map[i][j] != 'S')
				error_exit(cublx, fd, "Invalid character in map.");
			j++;
		}
		i++;
	}
}

static void	set_player(t_data *data, int i, int j, char dir)
{
	if (dir == 'N')
		data->player.camera->dir = cublx_vec2(0.0, -1.0);
	else if (dir == 'S')
		data->player.camera->dir = cublx_vec2(0.0, 1.0);
	else if (dir == 'E')
		data->player.camera->dir = cublx_vec2(1.0, 0.0);
	else if (dir == 'W')
		data->player.camera->dir = cublx_vec2(-1.0, 0.0);
	data->player.camera->pos = cublx_vec2((double)j + 0.5, (double)i + 0.5);
}

static void	check_player(t_cublx *cublx, int fd)
{
	int		i;
	int		j;
	bool	player;
	t_data	*data;

	i = 0;
	player = false;
	data = cublx->user->param;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'E'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'S')
			{
				if (player)
					error_exit(cublx, fd, "Too many player start positions.");
				player = true;
				set_player(data, i, j, data->map[i][j]);
			}
			j++;
		}
		i++;
	}
	if (!player)
		error_exit(cublx, fd, "No player start position found.");
}

static void	check_map_enclosure(t_cublx *cublx, int fd)
{
	int		i;
	int		j;
	char	**m;
	t_data	*data;

	i = 0;
	data = cublx->user->param;
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
					error_exit(cublx, fd, "Map is not closed by walls.");
			}
			j++;
		}
		i++;
	}
}

void	validate_map(t_cublx *cublx, int fd)
{
	check_letter(cublx, fd);
	check_player(cublx, fd);
	check_map_enclosure(cublx, fd);
}
