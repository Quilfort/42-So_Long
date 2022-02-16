NAME = so_long
LIBFT_DIR = ./library/libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = ./library/mlx
MLX_LIB = $(MLX_DIR)/libmlx.dylib
FLAGS = -Wall -Werror -Wextra -g -fsanitize=address
LFLAGS = -framework OpenGL -framework AppKit
INC = -I ./includes
SRC =   ./src/get_next_line/get_next_line.c \
		./src/get_next_line/get_next_line_utils.c \
		./src/start.c \
		./src/use_map.c \
		./src/error_map.c \
		./src/check_map.c \
		./src/write_map.c \
		./src/directions.c \
		./src/display_info.c \
		./src/exit_game.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(MLX_LIB) $(LIBFT) $(OBJ)
	gcc $(FLAGS) $(OBJ) -L. -lmlx $(LIBFT) $(LFLAGS) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) $(INC) -c $< -o $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)
	cd $(MLX_DIR) && cp ./libmlx.dylib ../../

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(OBJ) $(OBJ_BONUS) libmlx.dylib

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
