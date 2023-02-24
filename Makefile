# SRCS: find ./srcs -iname "*.c"

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
SRCS	= ./srcs/animation/animatable.c \
./srcs/animation/animation.c \
./srcs/animation/animation_alloc.c \
./srcs/animation/animation_list.c \
./srcs/animation/animation_query.c \
./srcs/animation/animation_update.c \
./srcs/game_context/actor_direction.c \
./srcs/game_context/context_management.c \
./srcs/game_context/enemies.c \
./srcs/game_context/fly_animation.c \
./srcs/game_context/fly_update.c \
./srcs/game_context/goblin_animation.c \
./srcs/game_context/goblin_update.c \
./srcs/game_context/input.c \
./srcs/game_context/map_alloc.c \
./srcs/game_context/map_position_query.c \
./srcs/game_context/map_query.c \
./srcs/game_context/player_collectables.c \
./srcs/game_context/player_collision.c \
./srcs/game_context/player_input.c \
./srcs/game_context/player_load.c \
./srcs/game_context/player_movement.c \
./srcs/game_context/player_ui.c \
./srcs/game_context/player_update.c \
./srcs/game_context/slime_animation.c \
./srcs/game_context/slime_update.c \
./srcs/game_context/update_enemy_collision.c \
./srcs/image/image_load.c \
./srcs/image/image_load_enemies.c \
./srcs/image/image_load_floor.c \
./srcs/image/image_load_player.c \
./srcs/image/image_load_props.c \
./srcs/image/image_load_text.c \
./srcs/image/image_load_tiles.c \
./srcs/image/image_load_ui.c \
./srcs/image/image_load_utils.c \
./srcs/image/image_load_walls.c \
./srcs/image/image_query.c \
./srcs/image/image_unload.c \
./srcs/map_loading/map_collectable_load.c \
./srcs/map_loading/map_enemy_element_load.c \
./srcs/map_loading/map_enemy_load.c \
./srcs/map_loading/map_exit_load.c \
./srcs/map_loading/map_floor_load.c \
./srcs/map_loading/map_load.c \
./srcs/map_loading/map_non_wall_prop_load.c \
./srcs/map_loading/map_player_end_load.c \
./srcs/map_loading/map_prop_load.c \
./srcs/map_loading/map_prop_query.c \
./srcs/map_loading/map_roof_corners_query.c \
./srcs/map_loading/map_roof_image_query.c \
./srcs/map_loading/map_roof_load.c \
./srcs/map_loading/map_roof_sides_query.c \
./srcs/map_loading/map_table_query.c \
./srcs/map_loading/map_torch_load.c \
./srcs/map_loading/map_wall_load.c \
./srcs/map_loading/map_wall_prop_load.c \
./srcs/map_loading/map_wall_query.c \
./srcs/map_parsing/line_count.c \
./srcs/map_parsing/map_reading.c \
./srcs/map_validate/map_assert_requirements.c \
./srcs/map_validate/map_asserts_usage.c \
./srcs/map_validate/map_components.c \
./srcs/map_validate/map_path_asserts.c \
./srcs/map_validate/path_finder.c \
./srcs/positioning/vector2_alloc.c \
./srcs/positioning/vector2_query.c \
./srcs/positioning/walk.c \
./srcs/so_long.c \
./srcs/string/string_alloc.c \
./srcs/string/string_arr_query.c \
./srcs/string/string_query.c \
./srcs/text/text_alloc.c \
./srcs/text/text_query.c \
./srcs/text/text_update.c \
./srcs/ui_loading/ui_element_load.c \
./srcs/ui_loading/ui_load.c \
./srcs/utils/list_utils.c \
./srcs/utils/rand_utils.c

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