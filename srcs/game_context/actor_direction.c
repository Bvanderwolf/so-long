/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actor_direction.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 13:18:54 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:51:21 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_utils.h"
#include "so_long_map.h"

bool	walks_into_closed_exit(t_context *gc, t_vector2 pos, t_vector2 walk_direction)
{
	t_map *const	map = gc->map;
	t_vector2		new_pos;
	bool			exit_is_closed;

	new_pos = vector2_new(pos.x + walk_direction.x, pos.y + walk_direction.y);
	exit_is_closed = gc->collectables != gc->player->collectables;
	return (is_map_tile(map, new_pos, MAP_EXIT) && exit_is_closed);
}

bool	walks_into_wall(t_context *gc, t_vector2 pos, t_vector2 walk_direction)
{
	char **const	map = gc->map->data;
	t_vector2		new_pos;

	new_pos = vector2_new(pos.x + walk_direction.x, pos.y + walk_direction.y);
	return (is_map_wall(map, new_pos.x, new_pos.y));
}

bool	is_invalid_direction(t_vector2 walk_direction)
{
	return (vector2_equals_xy(walk_direction, 0, 0));
}

// returns a random direction based on given map and the map position.
// it will not return directions towards walls and will return a direction
// of (0, 0) if the position is surrounded by walls.
t_vector2	get_random_direction(t_map *map, t_vector2 map_xy)
{
	int			i;
	int			rand_index;
	t_vector2	directions[4];

	i = 0;
	if (map_xy.y - 1 > 0 && !is_map_wall(map->data, map_xy.x, map_xy.y - 1)
		&& !is_map_tile_xy(map, map_xy.x, map_xy.y - 1, MAP_EXIT))
		directions[i++] = vector2_new(0, -1);
	if (map_xy.y + 1 < map->height - 1 && !is_map_wall(map->data, map_xy.x, map_xy.y + 1)
		&& !is_map_tile_xy(map, map_xy.x, map_xy.y + 1, MAP_EXIT))
		directions[i++] = vector2_new(0, 1);
	if (map_xy.x - 1 > 0 && !is_map_wall(map->data, map_xy.x - 1, map_xy.y)
		&& !is_map_tile_xy(map, map_xy.x - 1, map_xy.y, MAP_EXIT))
		directions[i++] = vector2_new(-1, 0);
	if (map_xy.x + 1 < map->width - 1 && !is_map_wall(map->data, map_xy.x + 1, map_xy.y)
		&& !is_map_tile_xy(map, map_xy.x + 1, map_xy.y, MAP_EXIT))
		directions[i++] = vector2_new(1, 0);
	if (i == 0)
		return (vector2_new(0, 0));
	rand_index = (int)rand_minmax(0.0, (float)i);
	return (directions[rand_index]);
}

// returns a random direction based on given map and the map position.
// it will also return directions towards non-outer walls.
t_vector2	get_random_direction_walls_ignored(t_map *map, t_vector2 map_xy)
{
	int			i;
	int			rand_index;
	t_vector2	directions[4];

	i = 0;
	if (map_xy.y - 1 > 0 && !is_outer_wall(map, map_xy.x, map_xy.y - 1))
		directions[i++] = vector2_new(0, -1);
	if (map_xy.y + 1 < map->height - 1 && !is_outer_wall(map, map_xy.x, map_xy.y + 1))
		directions[i++] = vector2_new(0, 1);
	if (map_xy.x - 1 > 0 && !is_outer_wall(map, map_xy.x - 1, map_xy.y))
		directions[i++] = vector2_new(-1, 0);
	if (map_xy.x + 1 < map->width - 1 && !is_outer_wall(map, map_xy.x + 1, map_xy.y))
		directions[i++] = vector2_new(1, 0);
	if (i == 0)
		return (vector2_new(0, 0));
	rand_index = (int)rand_minmax(0.0, (float)i);
	return (directions[rand_index]);
}
