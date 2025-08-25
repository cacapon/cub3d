# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 17:48:57 by yookamot          #+#    #+#              #
#    Updated: 2025/08/25 18:29:42 by yookamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = draw_vertical_line.c \
        exit_game.c \
        game_loop.c \
        init_game.c \
        load_textures.c \
        main.c \
        player_movement.c \
        ray_casting.c \
        read_map.c \
        set_move_lock.c

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -I./minilibx-linux
LDFLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm -lz -g

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(MLX) $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
