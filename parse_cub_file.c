/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:13:58 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/08 21:31:50 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_filename(t_data *data, char *file)
{
	int	i;

	i = ft_strlen(file);
	if (i < 4 || file[i - 1] != 'b' || file[i - 2] != 'u' || file[i - 3] != 'c'
		|| file[i - 4] != '.')
		error_exit(data, -1, NULL, "File must have a .cub extension.");
}

void	parse_cub_file(t_data *data, char *file)
{
	int	fd;

	check_filename(data, file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_exit(data, fd, NULL, "Failed to open cub file.");
	parse_texture_and_color(data, fd);
	parse_map(data, fd);
	close(fd);
}
