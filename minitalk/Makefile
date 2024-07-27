# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 16:02:52 by rbouizer          #+#    #+#              #
#    Updated: 2024/07/26 18:21:51 by rbouizer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_C = utils/ft_atoi.c\
	client.c

SRCS_S = server.c

OBJS_C = $(SRCS_C:.c=.o)
OBJS_S = $(SRCS_S:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -rf

C_NAME = client
S_NAME = server

all: $(C_NAME) $(S_NAME)


$(C_NAME): $(OBJS_C)
	$(CC) $(CFLAGS) -o $(C_NAME) $(OBJS_C)

$(S_NAME): $(OBJS_S)
	$(CC) $(CFLAGS) -o $(S_NAME) $(OBJS_S)

%.o: %.c minitalk.h utils/utils.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_C) $(OBJS_S)

fclean: clean
	$(RM) $(C_NAME) $(S_NAME) 

re: fclean all