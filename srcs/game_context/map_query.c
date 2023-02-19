/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_query.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/02 10:11:12 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/11 14:07:24 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "so_long.h"
#include "so_long_utils.h"

int	count_component_occurences(char **map, char c)
{
	int	count;
	int	x;
	int	y;

	y = 0;
	count = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == c)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

t_vector2	find_map_position(char **map, char c)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == c)
				return (vector2_new(x, y));
			x++;
		}
		y++;
	}
	return (vector2_new(0, 0));
}

bool	is_map_tile_xy(t_map *map, int x, int y, char tile)
{
	return (map->data[y][x] == tile);
}

bool	is_map_tile(t_map *map, t_vector2 position, char tile)
{
	return (is_map_tile_xy(map, position.x, position.y, tile));
}
