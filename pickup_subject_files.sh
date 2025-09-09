#!/bin/bash

SRC_DIR="./"
DEST_DIR="dest"

make fclean
mkdir -p "$DEST_DIR"

# ルート直下
cp --parents "$SRC_DIR"/*.c "$SRC_DIR"/*.h "$SRC_DIR"/Makefile "$DEST_DIR" 2>/dev/null

# cublibx
cp --parents "$SRC_DIR"/libs/cublibx/cublx.h "$SRC_DIR"/libs/cublibx/Makefile "$DEST_DIR" 2>/dev/null
cp -r --parents "$SRC_DIR"/libs/cublibx/libs/mlx "$DEST_DIR"
cp -r --parents "$SRC_DIR"/libs/cublibx/inc "$DEST_DIR"
cp -r --parents "$SRC_DIR"/libs/cublibx/srcs "$DEST_DIR"
cp -r --parents "$SRC_DIR"/libs/cublibx/objs "$DEST_DIR"

# maps / textures / get_next_line
cp -r --parents "$SRC_DIR"/maps "$DEST_DIR"
cp -r --parents "$SRC_DIR"/textures "$DEST_DIR"
cp --parents "$SRC_DIR"/get_next_line/*.c "$SRC_DIR"/get_next_line/*.h "$DEST_DIR" 2>/dev/null