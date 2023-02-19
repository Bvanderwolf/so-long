/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_prop_query.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/28 10:39:39 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/01/28 10:51:42 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "so_long.h"
#include "so_long_map.h"

bool	is_banner(t_map *map, int x, int y)
{
	return ((x > 1 && x < map->width - 2 && y == 0)
		&& (y + 1 < map->height - 1 && !is_map_wall(map->data, x, y + 1)));
}

bool	is_torch(t_map *map, int x, int y)
{
	return ((x == 1 && y == 0) || (x == map->width - 2 && y == 0));
}
