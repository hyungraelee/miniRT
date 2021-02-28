NAME = minirt
MLX = libmlx.dylib
MLX_DIR = ./lib/mlx

all : $(NAME)

$(NAME) : $(MLX_DIR)/$(MLX)
	gcc ./src/*.c ./src/*/*.c ./src/*/*/*.c -o $(NAME) -I./include -L$(MLX_DIR) -lmlx -I$(MLX_DIR)
	install_name_tool -change $(MLX) $(MLX_DIR)/$(MLX) $(NAME)

$(MLX_DIR)/$(MLX) :
	$(MAKE) -C $(MLX_DIR)

clean :
	rm -rf $(NAME) result.ppm

re :
	clean all

run : $(NAME)
	./$(NAME)

ppm : $(NAME)
	./$(NAME) > result.ppm

.PHONY : all clean re
