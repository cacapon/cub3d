/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublx_lib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:50:45 by ttsubo            #+#    #+#             */
/*   Updated: 2025/09/22 08:34:23 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBLX_LIB_H
# define CUBLX_LIB_H

# include <stddef.h>

void	*cublx_calloc(size_t count, size_t size);
void	*cublx_memchr(const void *s, int c, size_t n);
void	*cublx_memcpy(void *dst, const void *src, size_t len);
void	*cublx_memset(void *b, int c, size_t len);
char	*cublx_strchr(const char *s, int c);
char	*cublx_strdup(const char *s1);
size_t	cublx_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	cublx_strlen(const char *s);
char	*cublx_strtrim(char const *s1, char const *set);
void	cublx_perror(int errcode);

#endif