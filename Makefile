# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/04 18:19:15 by kmira             #+#    #+#              #
#    Updated: 2019/06/05 21:45:55 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME = fdf
LIBRARY = libft/libft.a

FILES = \
		main \
		input \

MLB = -L./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(LIBRARY) MLBlib
	@echo "\033[32m""Making your fdf executable"
	@gcc $(FLAGS) -c $(SRCS)
	@gcc $(MLB) -o $(NAME) $(OBJS) $(LIBRARY)
	@echo "\033[32m""Done!"

$(LIBRARY):
	@make -C libft/
	make clean -C libft/

MLBlib:
	@echo "\033[32m""Making minlibx"
	@make -C minilibx_macos/ clean && make -C minilibx_macos/

$(OBJ):
	gcc $(FLAGS) -c $(SRCS)

clean:
	@echo "Cleaning your .o files"
	@rm -f libft.a
	@rm -f $(OBJS)

fclean: clean
	@make -C minilibx_macos/ clean
	@make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

rebuild: clean
	rm -f $(NAME)
	make all
	make clean
	clear
