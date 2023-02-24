/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 10:30:12 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 15:10:42 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000

# define MAP_EXIT 'E'
# define MAP_ENTRY 'P'
# define MAP_COLLECTABLE 'C'
# define MAP_WALL '1'
# define MAP_FLOOR '0'
# define MAP_GOBLIN 'G'
# define MAP_SLIME 'S'
# define MAP_FLY 'F'

# define MAP_WALL_S "1"
# define MAP_EXIT_S "E"

# define MIN_MAP_SIZE 4

# define TILE_SIZE 32
# define TEXT_SIZE 20

# define WALL_HEIGHT TILE_SIZE
# define GUI_HEIGHT 112

# include "MLX42/MLX42.h"
# include "so_long_utils.h"
# include "libft.h"

typedef struct s_map
{
	char	**data;
	int		width;
	int		height;
}			t_map;

typedef struct s_player
{
	t_vector2	world_xy;
	t_vector2	map_xy;
	t_vector2	look_direction;
	t_walk		*walk;
	t_walk		*target_walk;
	t_list		*animations;
	int			collectables;
	int			steps;
}				t_player;

typedef struct s_context
{
	mlx_t		*mlx;
	t_map		*map;
	t_list		*images;
	t_list		*collision_hooks;
	t_list		*position_hooks;
	t_list		*animatables;
	t_list		*enemies;
	t_list		*effects;
	t_list		*text;
	t_player	*player;
	int			collectables;
	bool		completed;
}				t_context;

typedef enum e_keyinput
{
	KEY_UP		= 0,
	KEY_LEFT	= 1,
	KEY_DOWN	= 2,
	KEY_RIGHT	= 3
}	t_keyinput;

typedef enum e_collision
{
	COLLECTABLE_COLLISION	= 0,
	ENEMY_COLLISION			= 1
}	t_collision;

typedef void	(*t_collision_hook)(t_collision, t_context *);

typedef void	(*t_position_hook)(t_context *);

bool			game_init(t_context *gc);
void			game_terminate(t_context *gc);
void			exit_clearing_context(t_context *gc);
void			check_game_completion(t_context *gc);
void			end_game(const char *message, t_context *gc);

bool			load_map_into_context(t_context *gc, char **data);
void			unload_map(t_context *gc);

bool			is_key_pressed(t_keyinput key, mlx_key_data_t data);
t_vector2		get_walk_direction_from_input(mlx_key_data_t data);

bool			load_player(t_context *gc, t_vector2 world_position);
void			unload_player(t_context *gc);

bool			load_user_interface(t_context *gc);
bool			place_number(t_context *gc, const char *name, int x, int y);
bool			place_text(t_context *gc, const char *text, int margin);

void			render_player(void *context);

void			render_goblins(void *context);
void			update_goblin_walk_animation(t_context *gc, int map_x, \
int map_y);
void			render_goblin_animation(t_context *gc, int map_x, int map_y);

void			render_slimes(void *context);
void			update_slime_walk_animation(t_context *gc, int map_x, \
int map_y);
void			render_slime_animation(t_context *gc, int map_x, int map_y);

void			render_flies(void *context);
void			update_fly_walk_animation(t_context *gc, int map_x, int map_y);
void			render_fly_animation(t_context *gc, int map_x, int map_y);

void			handle_player_input(mlx_key_data_t keydata, void *context);
void			handle_player_collision(t_collision collider, t_context *gc);

bool			player_collision_hook(t_context *gc, t_collision_hook hook);
bool			player_position_hook(t_context *gc, t_position_hook hook);
void			invoke_player_collision(t_collision collider, t_context *gc);

bool			walks_into_closed_exit(t_context *gc, t_vector2 map_xy, \
t_vector2 walk_direction);
bool			walks_into_wall(t_context *gc, t_vector2 map_xy, \
t_vector2 walk_direction);
bool			walks_into_enemy(t_context *gc, t_vector2 world_xy, \
t_vector2 direction);
bool			is_invalid_direction(t_vector2 walk_direction);
t_vector2		get_random_direction(t_map *map, t_vector2 map_xy);
t_vector2		get_random_direction_walls_ignored(t_map *map, \
t_vector2 map_xy);

void			update_player_collectables(t_context *gc);
void			update_player_position(t_context *gc);
void			update_player_enemy_collision(t_context *gc);
void			update_player_steps_ui(t_context *gc);

mlx_instance_t	*get_collider(t_player *player, \
mlx_instance_t **instance_buffer, int instance_count, int squared_distance);

#endif