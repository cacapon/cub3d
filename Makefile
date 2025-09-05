# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 17:48:57 by yookamot          #+#    #+#              #
#    Updated: 2025/09/05 17:01:01 by ttsubo           ###   ########.fr        #
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
        move_player.c

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -I./libs/minilibx-linux
LDFLAGS = -L./libs/minilibx-linux -lmlx -lXext -lX11 -lm -lz -g

MLX_DIR = ./libs/minilibx-linux
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
