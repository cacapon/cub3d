/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx_errorcode.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 07:36:52 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/22 09:25:55 by ttsubo           ###   ########.fr       */
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
# define ERR_CUBLX_007 "Failed to load texture."
# define ERR_CUBLX_XXX "Unknown error code."

#endif