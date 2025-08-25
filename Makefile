# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 17:48:57 by yookamot          #+#    #+#              #
#    Updated: 2025/08/25 18:15:19 by ttsubo           ###   ########.fr        #
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
        read_map.c 

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -I./minilibx-linux -I./cublibx
LDFLAGS = -L./cublibx -lcublx -lXext -lX11 -lm -lz -g

CUBLX_DIR = ./cublibx
CUBLX = $(CUBLX_DIR)/libcublx.a

all: $(NAME)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(CUBLX):
	$(MAKE) -C $(CUBLX_DIR)

$(NAME): $(CUBLX) $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(CUBLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(CUBLX_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
