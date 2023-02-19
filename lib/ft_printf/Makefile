NAME	=	libftprintf.a
C_FLAGS	=	-Wall -Wextra -Werror
CC		=	cc

LIB		=	ar -rcs

RM		=	rm -rf

SRCS	=	conversion/conversion_string.c conversion/conversion.c conversion/conversion_state.c conversion/conversion_number_state.c \
			conversion/memory.c string/string_malloc.c string/string_query.c string/string_malloc_number.c \
			decimal/ft_atol.c printing/print_conversion_format.c printing/print_conversion_prefix.c printing/print_conversion.c \
			printing/print_utils.c ft_printf.c

OBJS	=	${SRCS:.c=.o}

all: ${NAME}

bonus: ${NAME}

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
