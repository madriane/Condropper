# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarandi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 14:27:59 by amarandi          #+#    #+#              #
#    Updated: 2017/12/27 14:54:59 by amarandi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dropeer
CC = gcc
LDLIBS =  -lft
LDFLAGS = -L ./libft
CPPFLAGS = -I ./includes
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
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@make -C libft
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette includes
