/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_wall_prop_load.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/28 10:08:09 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 14:05:46 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_utils.h"
#include "so_long_img.h"
#include "so_long_map.h"
#include <stdbool.h>

static void	set_prop_info(t_context *gc, char *name, t_vector2 offset, \
t_prop_info *info)
{
	info->img = find_image(gc->images, name);
	info->offset = offset;
}

static t_prop_info	get_wall_prop_info(t_context *gc, int x, int y)
{
	t_prop_info		info;
	t_map *const	map = gc->map;

	if (is_closet_wall(map, x, y))
	{
		set_prop_info(gc, IMG_CLOSET_WALL, vector2_new(0, -15), &info);
	}
	else if (is_long_table_left(map, x, y))
	{
		set_prop_info(gc, IMG_LONG_TABLE_WALL_LEFT, vector2_new(0, 2), &info);
	}
	else if (is_long_table_right(map, x, y))
	{
		set_prop_info(gc, IMG_LONG_TABLE_WALL_RIGHT, vector2_new(0, 2), &info);
	}
	else if (is_short_table(map, x, y))
	{
		set_prop_info(gc, IMG_SHORT_TABLE_WALL, vector2_new(0, 2), &info);
	}
	else
	{
		set_prop_info(gc, IMG_KEG_WALL, vector2_new(0, 0), &info);
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
