/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_position_query.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 14:32:36 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 16:08:00 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_map.h"
#include "so_long_utils.h"

t_vector2	map_to_world_position_xy(int x, int y)
{
	t_vector2	v;

	v.x = x * TILE_SIZE;
	v.y = (y * TILE_SIZE) + WALL_HEIGHT + (GUI_HEIGHT);
	return (v);
}

// Note to self: v.y = (map_position.y * TILE_SIZE) + TILE_SIZE
// naar v.y = (map_position.y * TILE_SIZE) + TILE_SIZE + GUI_HEIGHT.
// Dit om te compenseren voor de extra ui die bovenaan komt.
t_vector2	map_to_world_position(t_vector2 map_position)
{
	return (map_to_world_position_xy(map_position.x, map_position.y));
}

t_vector2	world_to_map_position_xy(int x, int y)
{
	t_vector2	v;

	v.x = (int)(x / (float)TILE_SIZE);
	v.y = (int)((y - WALL_HEIGHT - (GUI_HEIGHT)) / (float)TILE_SIZE);
	return (v);
}

t_vector2	world_to_map_position(t_vector2 world_position)
{
	return (world_to_map_position_xy(world_position.x, world_position.y));
}
