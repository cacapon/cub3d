/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:23:48 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/19 15:50:10 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_data *data;

	(void)argc;
	(void)argv;
	data = cub3d_init();
	printf("DBG: %f\n", data->player.pos.x);
	mlx_loop(data->mlx);
	return (0);
}
