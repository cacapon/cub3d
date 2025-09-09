/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:13:43 by yookamot          #+#    #+#             */
/*   Updated: 2025/09/06 18:58:36 by yookamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_to_leftstr(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin_gnl(left_str, buff);
	}
	free(buff);
	return (left_str);
}

static char	*ft_get_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (left_str[i] == '\n')
		i++;
	str = ft_substr(left_str, 0, i);
	return (str);
}

static char	*ft_new_left_str(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	i++;
	str = ft_substr(left_str, i, ft_strlen(left_str) - i);
	free(left_str);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > SIZE_MAX - 1)
		return (NULL);
	left_str = ft_read_to_leftstr(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}

// #include "get_next_line.h"
// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	// "test.txt" を読み取り専用で開く
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1) // ファイルを開けない場合
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	// get_next_lineを使ってファイルを1行ずつ読み込む
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line); // 読み取った行を出力
// 		free(line);         // メモリの解放
// 	}
// 	close(fd); // ファイルをクローズ
// 	return (0);
// }
