# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 07:19:09 by ttsubo            #+#    #+#              #
#    Updated: 2025/08/22 21:47:45 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libcublx.a
CC = cc

MLX_DIR = libs/mlx
W_FLG	= -Wall -Wextra -Werror
I_FLG	= -I. -I$(MLX_DIR)
L_FLG	= -Llib/mlx -lmlx -lX11 -lXext

OBJ_DIR 		= objs
OBJ_MLX_DIR		= $(OBJ_DIR)/mlx
OBJ_PRI_DIR		= $(OBJ_DIR)/private
OBJ_PUB_DIR		= $(OBJ_DIR)/public

PRI_SRCS_DIR	= srcs/private
PUB_SRCS_DIR	= srcs/public

PRI_SRCS = 	_cublx_calloc.c _cublx_btn.c _cublx_loop.c \
			_allocate_mlx.c _allocate_mlx_win.c _allocate_cublx_user.c \
			_cublx_key_just_pressed_init.c _cublx_key_state_init.c \
			_cublx_key_pressed.c _cublx_key_released.c 
PUB_SRCS = cublx_del.c cublx_new.c cublx_hook.c

SRCS = $(addprefix $(PRI_SRCS_DIR)/, $(PRI_SRCS)) \
	   $(addprefix $(PUB_SRCS_DIR)/, $(PUB_SRCS))
OBJS = $(addprefix $(OBJ_PRI_DIR)/,  $(PRI_SRCS:.c=.o)) \
	   $(addprefix $(OBJ_PUB_DIR)/,  $(PUB_SRCS:.c=.o))

all: $(NAME)

$(NAME): $(MLX_DIR)/libmlx_Linux.a $(OBJS)
	cd $(OBJ_DIR)/mlx && ar x ../../$<
	ar rcs $@ $(OBJ_MLX_DIR)/*.o $(OBJ_PRI_DIR)/*.o $(OBJ_PUB_DIR)/*.o

$(OBJ_PRI_DIR)/%.o: $(PRI_SRCS_DIR)/%.c
	$(CC) $(W_FLG) $(I_FLG) -c $< -o $@

$(OBJ_PUB_DIR)/%.o: $(PUB_SRCS_DIR)/%.c
	$(CC) $(W_FLG) $(I_FLG) -c $< -o $@

$(MLX_DIR)/libmlx_Linux.a: $(MLX_DIR)/mlx.h
	$(MAKE) -C $(MLX_DIR)

$(MLX_DIR)/mlx.h:
	git submodule update -i --recursive

clean:
	find $(OBJ_DIR) -type f -name "*.o" -exec rm {} +

fclean: clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re