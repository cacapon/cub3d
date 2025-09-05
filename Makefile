# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 17:48:57 by yookamot          #+#    #+#              #
#    Updated: 2025/09/05 19:45:46 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS =  main.c \
        game_loop.c \
        init_game.c \
        read_map.c \
        load_textures.c \
        free_array.c

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -I./libs/cublibx
LDFLAGS = -L./libs/cublibx -lcublx -lXext -lX11 -lm -lz -g

CUBLX_DIR = ./libs/cublibx
CUBLX = $(CUBLX_DIR)/libcublx.a

all: $(NAME)

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
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
