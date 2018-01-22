CC = clang
FILES = main errors init key_func fract_tree
SRC = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(FILES)))
DEBUG = -g -O3
FLAGS = -I. -pthread
CGFLAGS_LINUX = -lm -lmlx -lXext -lX11
CGFLAGS_MAC = -lmlx -framework OpenGL -framework AppKit
NAME = fractol

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	$(CC) $(DEBUG) -o $(NAME) $(OBJ) $(FLAGS) $(CGFLAGS_LINUX) libft/libft.a
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "fractol is done!"

libft/libft.a:
	@make -C libft/
obj/%.o: src/%.c
	$(CC) -c $^ -o $@ $(DEBUG) $(FLAGS)
clean:
	@rm -f $(OBJ)
	@make -C libft/ clean
	@printf '\033[33m[ ✔ ] %s\n\033[0m' "fractol: Clean"
fclean: clean
	@rm -f $(NAME)
	@rm -rf fractol.dSYM
	@rm -rf .draw.c.swp
	@make -C libft/ fclean
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "fractol: Fclean"
re: fclean all
