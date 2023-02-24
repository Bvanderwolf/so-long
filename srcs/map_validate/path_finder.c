/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_finder.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 11:36:25 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 10:33:12 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_utils.h"
#include <stdbool.h>

// returns whether a path in map "map" with size is possible
// from start to end using recursive backtracking.
//
// note: input map is modified.
bool	has_path(char **map, t_vector2 size, t_vector2 start, t_vector2 end)
{
	if (vector2_equals(start, end))
		return (true);
	map[start.y][start.x] = MAP_WALL;
	if (start.y > 0 && map[start.y - 1][start.x] != MAP_WALL)
	{
		if (has_path(map, size, vector2_add_xy(start, 0, -1), end))
			return (true);
	}
	if (start.y < size.y - 1 && map[start.y + 1][start.x] != MAP_WALL)
	{
		if (has_path(map, size, vector2_add_xy(start, 0, 1), end))
			return (true);
	}
	if (start.x > 0 && map[start.y][start.x - 1] != MAP_WALL)
	{
		if (has_path(map, size, vector2_add_xy(start, -1, 0), end))
			return (true);
	}
	if (start.x < size.x - 1 && map[start.y][start.x + 1] != MAP_WALL)
	{
		if (has_path(map, size, vector2_add_xy(start, 1, 0), end))
			return (true);
	}
	return (false);
}
