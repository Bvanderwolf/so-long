/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_load.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 10:49:42 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:48:31 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_utils.h"
#include "so_long_img.h"
#include "so_long_map.h"
#include <stdbool.h>
#include <stdio.h>

static bool	place_player(t_context *gc)
{
	t_vector2	position;

	position = map_to_world_position(find_map_position(gc->map->data, 'P'));
	return (load_player(gc, position));
}

bool	load_map_into_context(t_context *gc, char **data)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		return (false);
	map->data = data;
	map->width = ft_strtlen(data[0], '\n');
	map->height = str_arr_len(data);
	gc->map = map;
	return (true);
}

void	unload_map(t_context *gc)
{
	str_arr_free(gc->map->data);
	free(gc->map);
}

bool	load_map_tiles(t_context *gc)
{
	if (!load_floor(gc))
		return (false);
	if (!load_walls(gc))
		return (false);
	if (!load_collectables(gc))
		return (false);
	if (!load_exit(gc))
		return (false);
	if (!load_props(gc))
		return (false);
	if (!place_player(gc))
		return (false);
	if (!load_enemies(gc))
		return (false);
	if (!load_roofs(gc))
		return (false);
	return (true);
}
