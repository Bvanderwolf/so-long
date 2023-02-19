/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_alloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 14:52:47 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/01/17 09:25:33 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "so_long.h"
#include "so_long_utils.h"
#include "so_long_map.h"

// allocates memory for positions to be added to an array of positions
// where char 'c' occurs.
// returns (0) if allocation failed.
static bool	alloc_map_positions(char **map, t_vector2 **positions, char c)
{
	int			x;
	int			y;
	int			count;

	y = 0;
	count = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == c)
			{
				positions[count] = vector2_alloc(x, y);
				if (positions[count] == NULL)
					return (vector2_arr_free(positions), false);
				count++;
			}
			x++;
		}
		y++;
	}
	positions[count] = NULL;
	return (true);
}

// allocates memory for a null terminated array of map positions 
// where char 'c' occurs.
// returns (void *0) if allocation failed.
t_vector2	**find_map_positions(char **map, char c)
{
	t_vector2	**positions;
	int			size;

	size = count_component_occurences(map, c);
	positions = (t_vector2 **)malloc(sizeof(t_vector2 *) * (size + 1));
	if (positions == NULL)
		return (NULL);
	if (!alloc_map_positions(map, positions, c))
		return (NULL);
	return (positions);
}
