/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_roof_sides_query.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 15:12:15 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/01/17 17:10:54 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_img.h"
#include "so_long_utils.h"
#include "so_long_map.h"
#include <stdlib.h>
#include <stdio.h>

bool	is_roof_right(t_map *map, int x, int y)
{
	return (y >= 0 && y < map->height - 1 && x == 0);
}

bool	is_roof_left(t_map *map, int x, int y)
{
	return (y >= 0 && y < map->height - 1 && x == map->width - 1);
}

bool	is_roof_bottom(t_map *map, int x, int y)
{
	return (x > 0 && x < map->width - 1 && y == map->height - 1);
}

bool	is_roof_top(t_map *map, int x, int y)
{
	return (is_top_wall(map, x, y));
}
