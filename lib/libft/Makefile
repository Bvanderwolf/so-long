C_FLAGS = -Wall -Wextra -Werror

SRCS =  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c  ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
		ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c \
		ft_numlen_bonus.c ft_strtlen_bonus.c ft_strrchari_bonus.c ft_strchari_bonus.c \
		

SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

OBJS_REG = ${SRCS:.c=.o}

OBJS_BONUS = ${SRC_BONUS:.c=.o}

LIB = ar -rcs

CC = cc

NAME = libft.a

RM = rm -f

all:		${NAME}

.c.o:
			${CC} ${C_FLAGS} -c $< -o ${<:.c=.o}

clean:
			${RM} ${OBJS_REG} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

${NAME}:	${OBJS_REG} ${OBJS_BONUS}
			${LIB} ${NAME} ${OBJS_REG} ${OBJS_BONUS}

bonus:		${OBJS_BONUS}
			${LIB} ${NAME} ${OBJS_BONUS}

.PHONY:		all clean fclean re