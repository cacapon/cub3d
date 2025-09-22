/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx_errorcode.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 07:36:52 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/22 09:13:49 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBLX_ERRORCODE_H
# define CUBLX_ERRORCODE_H

typedef enum e_cublx_err
{
	E_CUBLX_000,
	E_CUBLX_001,
	E_CUBLX_002,
	E_CUBLX_003,
	E_CUBLX_004,
	E_CUBLX_005,
	E_CUBLX_006,
	E_CUBLX_007,
	E_CUBLX_XXX,
}	t_cublx_err;

# define ERR_CUBLX_000 "The variable is not ready."
# define ERR_CUBLX_001 "Failed to allocate memory."
# define ERR_CUBLX_002 "Failed to initialize mlx."
# define ERR_CUBLX_003 "Failed to create window."
# define ERR_CUBLX_004 "Failed to create view." 
# define ERR_CUBLX_005 "Failed to get data address." 
# define ERR_CUBLX_006 "Failed to create views." 
# define ERR_CUBKX_007 "Failed to load texture."
# define ERR_CUBLX_XXX "Unknown error code."

//TODO
// #define ERR_CUB3D_000 "Invalid number of arguments."
// #define ERR_CUB3D_001 "Failed to allocate cublx."
// #define ERR_CUB3D_002 "Failed to allocate memory."
// #define ERR_CUB3D_004 "File must have a .cub extension."
// #define ERR_CUB3D_005 "Failed to open cub file."
// #define ERR_CUB3D_006 "Invalid RGB format."
// #define ERR_CUB3D_007 "RGB value out of range."
// #define ERR_CUB3D_008 "Invalid element identifier."
// #define ERR_CUB3D_009 "Texture not set."
// #define ERR_CUB3D_010 "Color not set."
// #define ERR_CUB3D_011 "Invalid character in map."
// #define ERR_CUB3D_012 "Invalid dir"
// #define ERR_CUB3D_013 "Too many starts"
// #define ERR_CUB3D_014 "No player start position found."
// #define ERR_CUB3D_015 "Map is not closed by walls."
// #define ERR_CUB3D_016 ""
// #define ERR_CUB3D_017 ""
// #define ERR_CUB3D_018 ""
// #define ERR_CUB3D_019 ""
// #define ERR_CUB3D_020 ""

// error_exit(data, fd, "Failed to allocate memory.");
// error_exit(data, fd, "Failed to load texture.");
// error_exit(data, fd, "Failed to get image data address.");

#endif