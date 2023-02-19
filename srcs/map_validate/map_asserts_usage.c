/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_asserts_usage.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 11:19:34 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/09 12:10:15 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "so_long.h"
#include "so_long_utils.h"
#include "so_long_map.h"
#include "ft_printf.h"
#include "libft.h"

static bool	assert_single_use(char **map, char c)
{
	bool	found;
	int		x;
	int		y;

	found = false;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == c)
			{
				if (found)
					return (ft_printf(DUP_CHAR_MSG, c), false);
				found = true;
			}
			x++;
		}
		y++;
	}
	if (!found)
		return (ft_printf(MISSING_CHAR_MSG, c), false);
	return (true);
}

static bool	assert_use(char **map, char c)
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
				return (true);
			x++;
		}
		y++;
	}
	ft_printf(MISSING_CHAR_MSG, c);
	return (false);
}

bool	validate_map_content(char **map)
{
	if (!assert_single_use(map, MAP_ENTRY) || !assert_single_use(map, MAP_EXIT))
		return (false);
	if (!assert_use(map, MAP_COLLECTABLE))
		return (false);
	if (!assert_rectangular(map))
		return (false);
	if (!assert_wall_boxing(map))
		return (false);
	if (!assert_reachable_required_components(map))
		return (false);
	if (!assert_no_invalid_chars(map))
		return (false);
	return (true);
}
