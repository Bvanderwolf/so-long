/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_finder.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 11:36:25 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/13 12:47:04 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_utils.h"
#include <stdbool.h>

// returns whether a path in map "map" with size "s" is possible
// from position "p" to target "t" using recursive backtracking.
//
// note: input map is modified.
bool	has_path(char **map, t_vector2 s, t_vector2 p, t_vector2 t)
{
	if (vector2_equals(p, t))
		return (true);
	map[p.y][p.x] = MAP_WALL;
	if (p.y > 0 && map[p.y - 1][p.x] != MAP_WALL)
	{
		if (has_path(map, s, vector2_add_xy(p, 0, -1), t))
			return (true);
	}
	if (p.y < s.y - 1 && map[p.y + 1][p.x] != MAP_WALL)
	{
		if (has_path(map, s, vector2_add_xy(p, 0, 1), t))
			return (true);
	}
	if (p.x > 0 && map[p.y][p.x - 1] != MAP_WALL)
	{
		if (has_path(map, s, vector2_add_xy(p, -1, 0), t))
			return (true);
	}
	if (p.x < s.x - 1 && map[p.y][p.x + 1] != MAP_WALL)
	{
		if (has_path(map, s, vector2_add_xy(p, 1, 0), t))
			return (true);
	}
	return (false);
}
