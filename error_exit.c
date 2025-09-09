/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:19:10 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/09 17:02:50 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit(t_cublx *cublx, int fd, char *msg)
{
	if (msg)
	{
		write(2, "Error\n", 6);
		while (*msg)
			write(2, msg++, 1);
		write(2, "\n", 1);
	}
	if (fd != -1)
		close(fd);
	if (!cublx)
		exit(EXIT_FAILURE);
	else
		cublx->quit(cublx, EXIT_FAILURE);
}
