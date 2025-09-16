# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yookamot <yookamot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 17:48:57 by yookamot          #+#    #+#              #
#    Updated: 2025/09/16 16:53:14 by yookamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

GNL_SRCS = get_next_line/get_next_line.c \
           get_next_line/get_next_line_utils.c

SRCS =  main.c \
        game_loop.c \
        init_game.c \
        free_array.c \
        parse_cub_file.c \
        parse_texture_and_color.c \
        parse_map.c \
        validate_map.c \
        error_exit.c \
        utils.c \
        ft_split.c \
        ft_strtrim.c \
        draw_minimap.c \
        $(GNL_SRCS)

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./libs/cublibx -I./get_next_line
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
	$(MAKE) -C $(CUBLX_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
