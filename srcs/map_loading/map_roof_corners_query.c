/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_roof_corners_query.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 15:14:08 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/01/17 17:04:21 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_img.h"
#include "so_long_map.h"
#include "so_long_utils.h"
#include <stdlib.h>
#include <stdio.h>

bool	is_roof_corner_top_left(t_map *map, int x, int y)
{
	(void)map;
	return (x == 0 && y == 0);
}

bool	is_roof_corner_top_right(t_map *map, int x, int y)
{
	return (x == map->width - 1 && y == 0);
}

bool	is_roof_corner_bottom_left(t_map *map, int x, int y)
{
	return (x == 0 && y == map->height - 2);
}

bool	is_roof_corner_bottom_right(t_map *map, int x, int y)
{
	return (x == map->width - 1 && y == map->height - 2);
}

bool	is_top_corner(t_map *map, int x, int y)
{
	return ((x == 0 && y == 0) || (x == map->width - 1 && y == 0));
}
