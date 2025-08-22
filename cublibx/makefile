# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 07:19:09 by ttsubo            #+#    #+#              #
#    Updated: 2025/08/22 19:41:29 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libcublx.a
CC = cc

W_FLG	= -Wall -Wextra -Werror
I_FLG	= -I. -Iinc -Ilib/mlx -Ilib/libft
L_FLG	= -Llib/mlx -lmlx -lX11 -lXext

OBJ_DIR = obj
MLX_DIR = libs/mlx

all: $(NAME)

$(NAME): $(MLX_DIR)/libmlx_Linux.a

$(MLX_DIR)/libmlx_Linux.a: $(MLX_DIR)/mlx.h
	$(MAKE) -C $(MLX_DIR)

$(MLX_DIR)/mlx.h:
	git submodule update -i --recursive

clean:
	rm -f $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re