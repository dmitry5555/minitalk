# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 17:17:18 by dlariono          #+#    #+#              #
#    Updated: 2023/05/27 17:45:55 by dlariono         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minitalk.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

CLIENT = client
SERVER = server

SRC_CLIENT = client.c
OBJ_CLIENT = $(SRC_CLIENT:%.c=%.o)

SRC_SERVER = server.c
OBJ_SERVER = $(SRC_SERVER:%.c=%.o)

all: $(NAME)


$(NAME) : $(OBJ_CLIENT) $(OBJ_SERVER)
		@$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(CLIENT)
		@$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(SERVER)

clean:
		@$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
		@$(RM) $(CLIENT) $(SERVER)
		@$(RM)

re: fclean all
