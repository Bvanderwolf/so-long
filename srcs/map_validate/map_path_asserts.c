/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_path_asserts.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 11:31:16 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/13 12:33:45 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_utils.h"
#include "so_long_map.h"
#include "so_long.h"
#include "ft_printf.h"
#include <stdio.h>
#include <stdbool.h>

static bool	check_collectables(char **m, char **mc, t_vector2 s, t_vector2 p)
{
	t_vector2	**collectables;
	int			i;

	collectables = find_map_positions(m, MAP_COLLECTABLE);
	if (collectables == NULL)
	{
		perror("Failed creating collectable positions during map validation");
		return (false);
	}
	i = 0;
	while (collectables[i] != NULL)
	{
		if (!has_path(mc, s, p, *(collectables[i])))
		{
			ft_printf(UNREACHABLE_MSG, MAP_COLLECTABLE);
			return (vector2_arr_free(collectables), false);
		}
		str_arr_cpy(m, mc);
		i++;
	}
	vector2_arr_free(collectables);
	return (true);
}

bool	assert_reachable_required_components(char **map)
{
	char		**map_cpy;
	t_vector2	size;
	t_vector2	start;

	map_cpy = str_arr_dup(map);
	if (map == NULL)
		return (perror("Failed creating map copy during validation"), false);
	size = vector2_new(ft_strlen(map[0]), str_arr_len(map) - 1);
	start = find_map_position(map, MAP_ENTRY);
	if (!has_path(map_cpy, size, start, find_map_position(map, MAP_EXIT)))
		return (ft_printf(UNREACHABLE_MSG, MAP_EXIT), false);
	str_arr_cpy(map, map_cpy);
	if (!check_collectables(map, map_cpy, size, start))
		return (free(map_cpy), false);
	str_arr_free(map_cpy);
	return (true);
}
