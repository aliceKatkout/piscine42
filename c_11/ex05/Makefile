# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avedrenn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 11:40:54 by avedrenn          #+#    #+#              #
#    Updated: 2022/09/01 14:16:15 by avedrenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS= do.c do2.c operation.c

NAME= do-op

OBJS= $(SRCS:.c=.o)

INCLUDES= ./

CC= gcc

CFLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I $(INCLUDES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re all fclean clean
