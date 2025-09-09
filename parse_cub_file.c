/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:13:58 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/09 15:22:48 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_filename(t_cublx *cublx, char *file)
{
	int	i;

	i = ft_strlen(file);
	if (i < 4 || file[i - 1] != 'b' || file[i - 2] != 'u' || file[i - 3] != 'c'
		|| file[i - 4] != '.')
		error_exit(cublx, -1, "File must have a .cub extension.");
}

void	parse_cub_file(t_cublx *cublx, char *file)
{
	int		fd;
	t_data	*data;

	data = cublx->user->param;
	check_filename(cublx, file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_exit(cublx, fd, "Failed to open cub file.");
	parse_texture_and_color(data, cublx, fd);
	parse_map(cublx, fd);
	close(fd);
}
