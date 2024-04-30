# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 14:30:54 by anomourn          #+#    #+#              #
#    Updated: 2024/04/30 15:41:13 by anomourn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_B = server_bonus
NAME_CLIENT_B = client_bonus
PRINTF = ./printf
LIB = ./printf/libftprintf.a
SRC_SERVER = ./server.c
SRC_CLIENT = ./client.c
SRC_SERVER_B = ./server_bonus.c
SRC_CLIENT_B = ./client_bonus.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER_B = $(SRC_SERVER_B:.c=.o)
OBJ_CLIENT_B = $(SRC_CLIENT_B:.c=.o)
FLAGS = -g -Wall -Wextra -Werror
CC = cc

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	@make -C $(PRINTF)
	@$(CC) $(FLAGS) $(OBJ_SERVER) $(LIB) -o $(NAME_SERVER)
	@echo "Server ok"

$(NAME_CLIENT): $(OBJ_CLIENT) 
	@make -C $(PRINTF)
	@$(CC) $(FLAGS) $(OBJ_CLIENT) $(LIB) -o $(NAME_CLIENT)
	@echo "Client ok"


bonus: $(NAME_SERVER_B) $(NAME_CLIENT_B)

$(NAME_SERVER_B): $(OBJ_SERVER_B)
	@make -C $(PRINTF)
	@$(CC) $(FLAGS) $(OBJ_SERVER_B) $(LIB) -o $(NAME_SERVER_B)
	@echo "Server bonus ok"

$(NAME_CLIENT_B): $(OBJ_CLIENT_B) 
	@make -C $(PRINTF)
	@$(CC) $(FLAGS) $(OBJ_CLIENT_B) $(LIB) -o $(NAME_CLIENT_B)
	@echo "Client bonus ok"

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make clean -C $(PRINTF)
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_B) $(OBJ_CLIENT_B)

fclean: clean
	make fclean -C $(PRINTF)
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(OBJ_SERVER_B) $(OBJ_CLIENT_B)

re: fclean all

.PHONY: all clean fclean re
