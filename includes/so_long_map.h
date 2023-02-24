/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long_map.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 10:28:43 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 14:32:01 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_MAP_H
# define SO_LONG_MAP_H

# include "so_long_utils.h"
# include "so_long.h"
# include "so_long_img.h"
# include "so_long_anim.h"
# include <stdbool.h>

# define FLOOR_CHARS "0PCGSF"
# define NEIGHBOUR_COUNT 4
# define VALID_MAP_CHARS "01CPEGSF"

# define DUP_CHAR_MSG "Error\nMap contains duplicate '%c' characters\n"
# define MISSING_CHAR_MSG "Error\nMap misses required '%c' character\n"
# define NO_RECT_MAP_MSG "Error\nMap is not a rectangle\n"
# define NO_MIN_MAP_SIZE_MSG "Error\nMap size is smaller then minimum (2)\n"
# define MISSING_WALL_MSG "Error\nMap's %s wall is not complete\n"
# define UNREACHABLE_MSG "Error\nMap contains unreachable '%c' component\n"
# define INVALID_MAP_CHAR "Error\nMap contains invalid '%c' character\n"
# define INVALID_FILE_EXT "Error\nFile has invalid file extension\n"

# define BANNER_SPAWN_PERC 0.33f

typedef struct s_prop_info
{
	t_image		*img;
	t_vector2	offset;
}				t_prop_info;

// Map Load

bool		load_map_tiles(t_context *gc);

bool		load_floor(t_context *gc);
bool		load_walls(t_context *gc);
bool		load_wall_props(t_context *gc);
bool		load_non_wall_props(t_context *gc);
bool		load_collectables(t_context *gc);
bool		load_exit(t_context *gc);
bool		load_roofs(t_context *gc);
bool		load_props(t_context *gc);
bool		load_enemies(t_context *gc);
bool		load_torch_props(t_context *gc);
bool		load_player_ending(t_context *gc);

t_enemy		*load_slime(t_context *gc, int map_x, int map_y);
t_enemy		*load_goblin(t_context *gc, int map_x, int map_y);
t_enemy		*load_fly(t_context *gc, int map_x, int map_y);

mlx_image_t	*get_roof_image(t_context *gc, int x, int y);
mlx_image_t	*get_roof_top_corner_image(t_context *gc, int x, int y);

// Map query

bool		is_map_wall(char **map, int x, int y);
bool		is_top_corner(t_map *map, int x, int y);
bool		is_roof_corner_top_left(t_map *map, int x, int y);
bool		is_roof_corner_top_right(t_map *map, int x, int y);
bool		is_roof_corner_bottom_right(t_map *map, int x, int y);
bool		is_roof_corner_bottom_left(t_map *map, int x, int y);
bool		is_roof_right(t_map *map, int x, int y);
bool		is_roof_left(t_map *map, int x, int y);
bool		is_roof_bottom(t_map *map, int x, int y);
bool		is_roof_top(t_map *map, int x, int y);
bool		is_top_wall(t_map *map, int x, int y);
bool		is_outer_wall(t_map *map, int x, int y);
bool		is_map_tile(t_map *map, t_vector2 position, char tile);
bool		is_map_tile_xy(t_map *map, int x, int y, char tile);

bool		is_closet_wall(t_map *map, int x, int y);
bool		is_short_table(t_map *map, int x, int y);
bool		is_long_table_left(t_map *map, int x, int y);
bool		is_long_table_right(t_map *map, int x, int y);
bool		is_banner(t_map *map, int x, int y);
bool		is_torch(t_map *map, int x, int y);

t_vector2	find_map_position(char **map, char c);
t_vector2	map_to_world_position(t_vector2 map_position);
t_vector2	map_to_world_position_xy(int x, int y);
t_vector2	world_to_map_position(t_vector2 world_position);
t_vector2	world_to_map_position_xy(int x, int y);
t_vector2	**find_map_positions(char **map, char c);
int			count_component_occurences(char **map, char c);

// Map Parsing

int			count_lines(const char *file_name);
bool		check_file_extension(const char *file_name);
char		**read_map_file(const char *file_name, int size);
bool		validate_map_content(char **map);
bool		assert_reachable_required_components(char **map);
bool		assert_rectangular(char **map);
bool		assert_wall_boxing(char **map);
bool		assert_no_invalid_chars(char **map);

// Map components

bool		is_not_wall_or_nl(int c);

// Path finding

bool		has_path(char **map, t_vector2 size, t_vector2 start, \
t_vector2 end);

#endif