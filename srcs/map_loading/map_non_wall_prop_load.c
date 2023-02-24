/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_non_wall_prop_load.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/28 10:09:31 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 14:16:54 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_utils.h"
#include "so_long_img.h"
#include "so_long_map.h"
#include <stdbool.h>

static t_image	*get_banner_image(t_context *gc)
{
	float	perc;

	perc = rand() / (float)RAND_MAX;
	if (perc > BANNER_SPAWN_PERC)
		return (NULL);
	if (perc < (BANNER_SPAWN_PERC / 3))
		return (find_image(gc->images, IMG_BANNER_GREEN));
	if (perc < (BANNER_SPAWN_PERC / 3 * 2))
		return (find_image(gc->images, IMG_BANNER_RED));
	return (find_image(gc->images, IMG_BANNER_SKELETON));
}

static t_prop_info	get_non_wall_prop_info(t_context *gc, int x, int y)
{
	t_prop_info		info;
	t_map *const	map = gc->map;

	if (is_banner(map, x, y))
	{
		info.img = get_banner_image(gc);
		info.offset = vector2_new(0, 0);
	}
	else
	{
		info.img = NULL;
		info.offset = vector2_new(0, 0);
	}
	return (info);
}

static bool	place_non_wall_prop_tile(t_context *gc, int map_x, int map_y)
{
	t_prop_info		info;
	t_vector2		world_position;

	info = get_non_wall_prop_info(gc, map_x, map_y);
	if (info.img == NULL)
		return (true);
	world_position = map_to_world_position_xy(map_x, map_y);
	world_position = vector2_add(world_position, info.offset);
	return (mlx_image_to_window(gc->mlx,
			info.img->value,
			world_position.x,
			world_position.y
		) != -1);
}

static bool	place_non_animatable_props(t_context *gc)
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
			if (is_map_wall(data, x, y))
			{
				if (!place_non_wall_prop_tile(gc, x, y))
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

bool	load_non_wall_props(t_context *gc)
{
	if (!place_non_animatable_props(gc))
		return (false);
	if (!load_torch_props(gc))
		return (false);
	return (true);
}
