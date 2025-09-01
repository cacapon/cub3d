/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:13:58 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/01 21:10:55 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <string.h> // strdupを使う場合

#define MAP_HEIGHT 7

void	read_map(t_data *data)
{
	data->map = (char **)malloc(sizeof(char *) * MAP_HEIGHT);
	if (!data->map)
		exit(1);
	data->map[0] = strdup("1111111111");
	data->map[1] = strdup("1000000001");
	data->map[2] = strdup("1010001001");
	data->map[3] = strdup("1000001001");
	data->map[4] = strdup("10N1001001");
	data->map[5] = strdup("1001000001");
	data->map[6] = strdup("1111111111");
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		if (!data->map[i])
		{
			for (int j = 0; j < i; j++)
				free(data->map[j]);
			free(data->map);
			exit(1);
		}
	}
}
