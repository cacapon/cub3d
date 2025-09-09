# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 07:19:09 by ttsubo            #+#    #+#              #
#    Updated: 2025/09/09 16:45:07 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libcublx.a
CC = gcc

MLX_DIR = libs/mlx
W_FLG	= -Wall -Wextra -Werror
I_FLG	= -I. -Iinc -I$(MLX_DIR)
L_FLG	= -Llib/mlx -lmlx -lX11 -lXext

OBJ_DIR 		= objs
OBJ_MLX_DIR		= $(OBJ_DIR)/mlx
OBJ_PRI_DIR		= $(OBJ_DIR)/private
OBJ_PUB_DIR		= $(OBJ_DIR)/public
OBJ_UTIL_DIR	= $(OBJ_PUB_DIR)/utils

PRI_SRCS_DIR	= srcs/private
PUB_SRCS_DIR	= srcs/public
PUB_UTIL_DIR	= $(PUB_SRCS_DIR)/utils

PRI_SRCS = 	_cublx_loop.c \
			_allocate_view.c \
			_cublx_btn.c _cublx_btnp.c _cublx_pset.c _cublx_quit.c \
			_cublx_load_xpm.c _cublx_free_tex.c _cublx_raycasting.c _cublx_draw_line.c \
			_cublx_camera_get_ray.c _cublx_camera_move.c \
			_cublx_camera_rotate.c _cublx_camera_set_fov.c _cublx_camera_set_view.c \
			_cublx_key_just_pressed_init.c _cublx_key_state_init.c \
			_cublx_key_pressed.c _cublx_key_released.c 
PUB_SRCS = 	cublx_del.c cublx_new.c \
			cublx_vec2.c cublx_vec2i.c \
			cublx_camera_new.c cublx_camera_del.c \
			cublx_get_tex_color.c \
			cublx_run.c cublx_set_hooks.c cublx_set_user_param.c 
PUB_UTILS = cublx_calloc.c cublx_memchr.c cublx_memcpy.c cublx_memset.c \
			cublx_strchr.c cublx_strdup.c cublx_strlcpy.c cublx_strlen.c cublx_strtrim.c

SRCS = $(addprefix $(PRI_SRCS_DIR)/, $(PRI_SRCS)) \
	   $(addprefix $(PUB_SRCS_DIR)/, $(PUB_SRCS)) \
	   $(addprefix $(PUB_UTIL_DIR)/, $(PUB_UTILS))
OBJS = $(addprefix $(OBJ_PRI_DIR)/,  $(PRI_SRCS:.c=.o)) \
	   $(addprefix $(OBJ_PUB_DIR)/,  $(PUB_SRCS:.c=.o)) \
	   $(addprefix $(OBJ_UTIL_DIR)/,  $(PUB_UTILS:.c=.o))


all: $(NAME)

$(NAME): $(MLX_DIR)/libmlx_Linux.a $(OBJS)
	cd $(OBJ_DIR)/mlx && ar x ../../$<
	ar rcs $@ $(OBJ_MLX_DIR)/*.o $(OBJ_PRI_DIR)/*.o $(OBJ_PUB_DIR)/*.o $(OBJ_UTIL_DIR)/*.o

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