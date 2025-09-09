/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:27:22 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/05 19:13:11 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEMO_H
# define DEMO_H

# include "cublx.h"

typedef t_cublx_camera	t_camera;

typedef struct s_textures
{
	t_img		north;
	t_img		south;
	t_img		east;
	t_img		west;
}				t_textures;

typedef struct s_data
{
	t_textures	textures;
	int			floor_color;
	int			ceiling_color;
	char		**map;
	t_camera	*player;
}				t_data;

#endif