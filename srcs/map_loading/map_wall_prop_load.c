/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_wall_prop_load.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/28 10:08:09 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:47:48 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_utils.h"
#include "so_long_img.h"
#include "so_long_map.h"
#include <stdbool.h>

static t_prop_info	get_wall_prop_info(t_context *gc, int x, int y)
{
	t_prop_info		info;
	t_map *const	map = gc->map;

	if (is_closet_wall(map, x, y))
	{
		info.img = find_image(gc->images, IMG_CLOSET_WALL);
		info.offset = vector2_new(0, -15);
	}
	else if (is_long_table_left(map, x, y))
	{
		info.img = find_image(gc->images, IMG_LONG_TABLE_WALL_LEFT);
		info.offset = vector2_new(0, 2);
	}
	else if (is_long_table_right(map, x, y))
	{
		info.img = find_image(gc->images, IMG_LONG_TABLE_WALL_RIGHT);
		info.offset = vector2_new(0, 2);
	}
	else if (is_short_table(map, x, y))
	{
		info.img = find_image(gc->images, IMG_SHORT_TABLE_WALL);
		info.offset = vector2_new(0, 2);
	}
	else
	{
		info.img = find_image(gc->images, IMG_KEG_WALL);
		info.offset = vector2_new(0, 0);
	}
	return (info);
}

static bool	place_wall_prop_tile(t_context *gc, int map_x, int map_y)
{
	t_prop_info		info;
	t_vector2		world_position;

	info = get_wall_prop_info(gc, map_x, map_y);
	world_position = map_to_world_position_xy(map_x, map_y);
	world_position = vector2_add(world_position, info.offset);
	return (mlx_image_to_window(gc->mlx,
			info.img->value,
			world_position.x,
			world_position.y
		) != -1);
}

bool	load_wall_props(t_context *gc)
{
	char **const	data = gc->map->data;
	int				x;
	int				y;

	y = 0;
	while (data[y] != NULL)
	{
		x = 0;
		while (data[y][x] != '\0')
		{
			if (is_map_wall(data, x, y) && !is_outer_wall(gc->map, x, y))
			{
				if (!place_wall_prop_tile(gc, x, y))
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}
