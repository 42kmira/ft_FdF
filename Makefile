# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/04 18:19:15 by kmira             #+#    #+#              #
#    Updated: 2019/06/07 18:24:11 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
INCLUDES = includes
NAME = fdf
LIBRARY = libft/libft.a

FILES = \
		main \
		input \
		point_matrix \

MLB = -L./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

SRCS = $(addprefix srcs/, $(addsuffix .c, $(FILES)))
OBJS = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(LIBRARY) MLBlib
	@echo "\033[32m""Making your fdf executable"
	@gcc $(FLAGS) -I$(INCLUDES) -c $(SRCS)
	@gcc $(MLB) -o $(NAME) $(OBJS) $(LIBRARY)
	@echo "\033[32m""Done!"

$(LIBRARY):
	@make -C libft/
	make clean -C libft/

MLBlib:
	@echo "\033[32m""Making minlibx"
	@make -C minilibx_macos/ clean && make -C minilibx_macos/

$(OBJ):
	gcc $(FLAGS) -I$(INCLUDES) -c $(SRCS)

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
