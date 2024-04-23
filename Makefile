# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 14:30:54 by anomourn          #+#    #+#              #
#    Updated: 2024/04/23 14:45:47 by anomourn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client
PRINTF = ./printf
LIB = ./printf/libftprintf.a
SRC_SERVER = ./server.c
SRC_CLIENT = ./client.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
FLAGS = -g -Wall -Wextra -Werror
CC = cc

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	@make -C $(PRINTF)
	@$(CC) $(FLAGS) $(OBJ_SERVER) $(LIB) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) 
	@make -C $(PRINTF)
	@$(CC) $(FLAGS) $(OBJ_CLIENT) $(LIB) -o $(NAME_CLIENT)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make clean -C $(PRINTF)
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	make fclean -C $(PRINTF)
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re
