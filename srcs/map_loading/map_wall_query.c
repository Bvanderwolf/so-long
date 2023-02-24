/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_wall_query.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 15:31:46 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 13:59:30 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_img.h"
#include "so_long_utils.h"
#include "so_long_map.h"
#include <stdlib.h>

// returns whether a wall is located on
// given map at position xy.
bool	is_map_wall(char **map, int x, int y)
{
	return (map[y][x] == MAP_WALL);
}

// returns whether a wall at position x/y is renderable
bool	is_top_wall(t_map *map, int x, int y)
{
	return (x > 0 && x < map->width - 1 && y == 0);
}

bool	is_outer_wall(t_map *map, int x, int y)
{
	return ((x >= 0 && x < map->width && y == 0)
		|| (x >= 0 && x < map->width && y == map->height - 1)
		|| (y >= 0 && y < map->height && x == 0)
		|| (y >= 0 && y < map->height && x == map->width - 1));
}

bool	is_closet_wall(t_map *map, int x, int y)
{
	return (x > 1 && x < map->width - 2
		&& y - 1 >= 0 && is_top_wall(map, x, y - 1));
}
