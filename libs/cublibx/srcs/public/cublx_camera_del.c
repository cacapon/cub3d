/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx_camera_del.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:35:15 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/01 18:16:46 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublx_camera.h"
#include <stdlib.h>

/**
 * @brief Delete the camera instance.
 *
 * @param camera
 * @return int
 */
int	cublx_camera_del(t_camera **camera)
{
	if (!camera || !*camera)
		return (1);
	free(*camera);
	*camera = NULL;
	return (0);
}
