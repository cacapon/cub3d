/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:19:10 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/08 21:57:27 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit(t_data *data, int fd, char **array, char *msg)
{
	if (array)
		free_array(array);
	if (msg)
	{
		write(2, "Error\n", 6);
		while (*msg)
			write(2, msg++, 1);
		write(2, "\n", 1);
	}
	if (fd != -1)
	{
		get_next_line(-42);
		close(fd);
	}
	exit_game(data, EXIT_FAILURE);
}
