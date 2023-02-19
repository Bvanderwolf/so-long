NAME	=	get_next_line.a
C_FLAGS	=	-Wall -Wextra -Werror
CC		=	cc

LIB		=	ar -rcs

RM		=	rm -rf

SRCS	=	get_next_line.c get_next_line_utils.c

OBJS	=	${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${LIB} ${NAME} $^

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re

%.o: %.c
	${CC} ${C_FLAGS} -o $@ -c $^