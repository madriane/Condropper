# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarandi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 14:27:59 by amarandi          #+#    #+#              #
#    Updated: 2017/12/19 21:38:10 by amarandi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = puissance4
CC = gcc
LDLIBS = -lft
LDFLAGS = -Llibft
CPPFLAGS = -Iincludes
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = src
SRC_NAME = main.c\
		   gridder.c\
		   victory.c\
		   players.c
OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

.PHONY: all, clean, fclean, re, norme

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	make -C libft
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	make -C libft clean

fclean: clean
	rm -fv $(NAME)
	make -C libft fclean

re: fclean all

norme:
	norminette $(SRC)
	norminette includes
