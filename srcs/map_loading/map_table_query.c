/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_table_query.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 13:59:20 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 13:59:39 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_img.h"
#include "so_long_utils.h"
#include "so_long_map.h"
#include <stdlib.h>

bool	is_short_table(t_map *map, int x, int y)
{
	return (y > 1 && y < map->height - 2
		&& (x == 1 || x == map->width - 2));
}

bool	is_long_table_left(t_map *map, int x, int y)
{
	return ((is_outer_wall(map, x - 1, y) || !is_map_wall(map->data, x - 1, y))
		&& (!is_outer_wall(map, x + 1, y) && is_map_wall(map->data, x + 1, y)));
}

bool	is_long_table_right(t_map *map, int x, int y)
{
	return ((!is_outer_wall(map, x - 1, y) && is_map_wall(map->data, x - 1, y))
		&& (x - 2 > 0 && !is_map_wall(map->data, x - 2, y)));
}
