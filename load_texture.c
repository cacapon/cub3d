/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:59:24 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/08 21:35:11 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_xpm(t_data *data, t_img *img, char **array, int fd)
{
	char	*trimmed;

	trimmed = ft_strtrim(array[1], " \n\t\r");
	if (!trimmed)
		error_exit(data, fd, array, "Failed to allocate memory.");
	img->img = mlx_xpm_file_to_image(data->mlx, trimmed, &img->width,
			&img->height);
	free(trimmed);
	if (!img->img)
		error_exit(data, fd, array, "Failed to load texture.");
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		error_exit(data, fd, array, "Failed to get image data address.");
}
