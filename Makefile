NAME = cub3D

# GNL ソース
GNL_SRCS = get_next_line/get_next_line.c \
           get_next_line/get_next_line_utils.c

# cub3d ソース
SRCS = draw_vertical_line.c \
        exit_game.c \
        game_loop.c \
        init_game.c \
        main.c \
        player_movement.c \
        ray_casting.c \
        parse_cub_file.c \
        parse_texture_and_color.c \
        parse_map.c \
        validate_map.c \
        move_player.c \
        error_exit.c \
        utils.c \
        ft_split.c \
        ft_strtrim.c \
        $(GNL_SRCS)

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./minilibx-linux -I./get_next_line
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
