# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/04 18:19:15 by kmira             #+#    #+#              #
#    Updated: 2019/06/04 18:32:34 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME = fdf
LIBRARY = libft/libft.a

FILES = \
		main

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .c, $(FILES))

all: $(NAME)

$(NAME): $(LIBRARY)
	@echo "\033[32m""Making your fdf executable"
	@gcc -o $(NAME) $(OBJS) $(LIBRARY)
	@echo "\033[32m""Done!"

$(LIBRARY):
	@make -C libft/
	make clean -C libft/

$(OBJ):
	gcc $(FLAGS) -c $(SRCS)

clean:
	@echo "Cleaning your .o files"
	@rm -f libft.a
	@rm -f $(OBJS)

fclean: clean
	@make -C fclean libft/
	rm -f $(NAME)

re: fclean all
