NAME = miniRT
CC = gcc
CFLAGS = -g3 -fsanitize=address #-Wall -Wextra -Werror
AR = ar
ARFLAGS = rc
SRCS =	./srcs/main.c						\
		./srcs/gnl/get_next_line.c			\
		./srcs/gnl/get_next_line_utils.c	\
		./srcs/mlx_cntl/rendering.c			\
		./srcs/mlx_cntl/set_mlx.c			\
		./srcs/mlx_cntl/color.c				\
		./srcs/mlx_cntl/control/control.c	\
		./srcs/parse/parse.c				\
		./srcs/parse/parse_utils.c			\
		./srcs/parse/parse_err.c			\
		./srcs/scene/camera.c				\
		./srcs/scene/canvas.c				\
		./srcs/scene/ambient.c				\
		./srcs/scene/object_create.c		\
		./srcs/trace/hit/hit.c				\
		./srcs/trace/hit/normal.c			\
		./srcs/trace/hit/hit_cylinder.c		\
		./srcs/trace/hit/hit_plane.c		\
		./srcs/trace/hit/hit_sphere.c		\
		./srcs/trace/hit/hit_square.c		\
		./srcs/trace/hit/hit_triangle.c		\
		./srcs/trace/ray/phong_lighting.c	\
		./srcs/trace/ray/ray.c				\
		./srcs/trans/translate.c			\
		./srcs/trans/rotate.c				\
		./srcs/trans/scale.c				\
		./srcs/utils/object_utils.c			\
		./srcs/utils/vec3_utils.c			\
		./srcs/bitmap/bitmap.c

SRCS_NAME = $(SRCS:%.c=%)

SRCS_DIR =	./srcs				\
			./srcs/gnl			\
			./srcs/mlx_cntl		\
			./srcs/mlx_cntl/control \
			./srcs/parse		\
			./srcs/scene		\
			./srcs/trace/hit	\
			./srcs/trace/ray	\
			./srcs/trans		\
			./srcs/utils		\
			./srcs/bitmap

OBJS_DIR = ./objs
LIBFT = libft.a
LIBFT_DIR = ./lib/libft
INC = ./includes
RM = rm -f
MLX = libmlx.dylib
MLX_DIR = ./lib/mlx
vpath %.c $(SRCS_DIR)
OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx
	@install_name_tool -change $(MLX) $(MLX_DIR)/$(MLX) $(NAME)

$(OBJS_DIR) :
	# @mkdir -p $(OBJ_DIR)

$(OBJS_DIR)/%.o : %.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(INC) -c $<

bonus : all

clean :
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean
	@$(RM) -r $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all
