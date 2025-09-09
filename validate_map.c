/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 15:44:28 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/09 18:04:22 by ttsubo           ###   ########.fr       */
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

static void	set_player(t_cublx *cublx, t_vec2i pos, char dir, int fd)
{
	t_vec2		vec_dir;
	t_data		*data;
	t_camera	*camera;

	if (dir == 'N')
		vec_dir = cublx_vec2(0.0, -1.0);
	else if (dir == 'S')
		vec_dir = cublx_vec2(0.0, 1.0);
	else if (dir == 'E')
		vec_dir = cublx_vec2(1.0, 0.0);
	else if (dir == 'W')
		vec_dir = cublx_vec2(-1.0, 0.0);
	else
		error_exit(cublx, fd, "Invalid dir");
	data = cublx->user->param;
	camera = data->player.camera;
	camera->pos = cublx_vec2((double)pos.x + 0.5, (double)pos.y + 0.5);
	camera->set_view(camera, camera->pos, vec_dir, FOV);
}

static void	check_player(t_cublx *cublx, int fd)
{
	t_vec2i	pos;
	bool	player;
	t_data	*d;

	pos.y = -1;
	player = false;
	d = cublx->user->param;
	while (d->map[++pos.y])
	{
		pos.x = -1;
		while (d->map[pos.y][++pos.x])
		{
			if (ft_strchr("NEWS", d->map[pos.y][pos.x]) != NULL)
			{
				if (player)
					error_exit(cublx, fd, "Too many starts");
				player = true;
				set_player(cublx, pos, d->map[pos.y][pos.x], fd);
			}
		}
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
			if (m[i][j] == '0' || m[i][j] == 'N' || m[i][j] == 'E'
				|| m[i][j] == 'W' || m[i][j] == 'S')
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
