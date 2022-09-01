SRCS	= good_format.c parse_mesh.c parse_peers.c show_number.c show_numbers2.c tools0.c tools1.c tools2.c main.c

OBJS	= ${SRCS:.c=.o}

NAME	= rush-02

.c.o:
		gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		gcc -Wall -Wextra -Werror ${OBJS} -o ${NAME}

all:	${NAME}

clean:
		rm -f ${OBJS}

fclean:		clean
		rm -f ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
