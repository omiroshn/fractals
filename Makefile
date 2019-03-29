# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 22:19:29 by omiroshn          #+#    #+#              #
#    Updated: 2018/01/31 22:19:34 by omiroshn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = clang
FILES = main \
		init \
		draw \
		iter \
		iter2 \
		iter3 \
		errors \
		key_func
LIBFT_DIR = libft/
SRC = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(FILES)))
OBJ_LIST = $(addsuffix .o, $(FILES))
SPEED = -O3
FLAGS = -Wall -Wextra -Werror
HEADERS = -I./includes -I./libft/includes
CGFLAGS_LINUX = -lm -lmlx -lXext -lX11 -pthread
CGFLAGS_MAC = -I /Library/Developer/CommandLineTools/usr/include/ -g -L /Library/Developer/CommandLineTools/usr/lib/ -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

.PHONY: all clean
.NOTPARALLEL: all $(NAME) clean fclean re 

$(NAME): libft/libft.a $(OBJ)
	@echo "\033[36mLinking...\033[0m"
	@$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(SPEED) $(CGFLAGS_MAC) libft/libft.a
	@echo "\033[32m[ ✔ ] Binary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"
libft/libft.a:
	@make --no-print-directory -C $(LIBFT_DIR)
obj/%.o: src/%.c
	@$(CC) -o $@ $(FLAGS) $(SPEED) $(HEADERS) -c $^
	@echo "\033[37mCompilation of \033[97m$(notdir $<) \033[0m\033[37mdone. \033[0m"
clean:
	@rm -f $(OBJ)
	@make --no-print-directory -C libft/ clean
	@echo "\033[31m[ ✔ ] Objects files \033[91m$(OBJ_LIST) \033[0m\033[31m removed. \033[0m"
fclean:
	@rm -rf $(OBJ)
	@rm -f $(NAME)
	@make --no-print-directory -C libft/ fclean
	@echo "\033[31m[ ✔ ] Objects files \033[91m$(OBJ_LIST) \033[0m\033[31m removed. \033[0m"
	@echo "\033[31m[ ✔ ] Binary \033[1;31m$(NAME) \033[1;0m\033[31mremoved.\033[0m"
re: fclean all
