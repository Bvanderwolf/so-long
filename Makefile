# //= Variables =//

NAME	= so_long
LIBMLX	= ./lib/mlx
LIBFT	= ./lib/libft
LIBPF	= ./lib/ft_printf
LIBGN	= ./lib/get_next_line

ifdef SANITIZE
DFLAGS	= -g -fsanitize=address
else
DFLAGS	= 
endif

ifdef NOERROR
CFLAGS	= -Wunreachable-code -Ofast
else
CFLAGS	= -Wunreachable-code -Ofast -Wall -Werror -Wextra
endif

HEADERS	= -I ./includes -I ${LIBMLX}/include -I ${LIBFT} -I ${LIBGN} -I ${LIBPF}
LIBGL	= -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
LIBS	= ${LIBGL} ${LIBMLX}/libmlx42.a ${LIBFT}/libft.a ${LIBPF}/libftprintf.a ${LIBGN}/get_next_line.a
SRCS	= ${shell find ./srcs -iname "*.c"} ## vervangen met SRCS van makefile old door command te gebruiken en resultaat te gebruiken als SRCS
OBJS	= ${SRCS:.c=.o}

BOLD	= \033[1m
BLACK	= \033[30;1m
RED		= \033[31;1m
GREEN	= \033[32;1m
YELLOW	= \033[33;1m
BLUE	= \033[34;1m
MAGENTA	= \033[35;1m
CYAN	= \033[36;1m
WHITE	= \033[37;1m
RESET	= \033[0m

# //= Recipes =//

all: libft libmlx libpf libgn ${NAME}

libft:
	@${MAKE} -C ${LIBFT}

libmlx:
	@${MAKE} -C ${LIBMLX}

libpf:
	@${MAKE} -C ${LIBPF}

libgn:
	@${MAKE} -C ${LIBGN}

%.o: %.c
	@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS} && printf "${GREEN}${BOLD}\rCompiling: ${notdir $<}\r\e[35C[OK]\n${RESET}"

${NAME}: ${OBJS}
	@${CC} ${DFLAGS} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

clean:
	@rm -f ${OBJS}
	@${MAKE} -C ${LIBFT} clean
	@${MAKE} -C ${LIBMLX} clean
	@${MAKE} -C ${LIBPF} clean
	@${MAKE} -C ${LIBGN} clean

fclean: clean
	@rm -f ${NAME}
	@${MAKE} -C ${LIBFT} fclean
	@${MAKE} -C ${LIBMLX} fclean
	@${MAKE} -C ${LIBPF} fclean
	@${MAKE} -C ${LIBGN} fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft