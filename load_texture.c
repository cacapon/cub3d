/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:59:24 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/06 20:01:44 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_xpm(t_data *data, t_img *img, char *path, int fd)
{
	char	*trimmed;

	trimmed = ft_strtrim(path, " \n\t\r");
	if (!trimmed)
		error_exit(data, fd, "Failed to allocate memory.");
	img->img = mlx_xpm_file_to_image(data->mlx, trimmed, &img->width,
			&img->height);
	free(trimmed);
	if (!img->img)
		error_exit(data, fd, "Failed to load texture.");
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		error_exit(data, fd, "Failed to get image data address.");
}
