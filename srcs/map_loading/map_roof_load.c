/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_roof_load.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 15:06:27 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:48:17 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_utils.h"
#include "so_long_img.h"
#include "so_long_map.h"
#include <stdbool.h>
#include <stdio.h>

static bool	place_roof_on_wall(t_context *gc, int map_x, int map_y)
{
	t_image		*image;
	t_vector2	world_position;

	image = find_image(gc->images, IMG_ROOF_TOP);
	world_position = map_to_world_position_xy(map_x, map_y - 1);
	return (mlx_image_to_window(gc->mlx,
			image->value,
			world_position.x,
			world_position.y
		) != -1);
}

// places roof tile based on position. will reposition roof tiles
// at the bottom to be overlaying the bottom floor.
static bool	place_roof_without_wall(t_context *gc, int map_x, int map_y)
{
	mlx_image_t	*image;
	t_vector2	position;

	image = get_roof_image(gc, map_x, map_y);
	if (image == NULL)
		return (true);
	if (map_y == gc->map->height - 1)
		map_y = gc->map->height - 2;
	position = map_to_world_position_xy(map_x, map_y);
	return (mlx_image_to_window(gc->mlx, image, position.x, position.y) != -1);
}

static bool	place_roof_top_corner(t_context *gc, int map_x, int map_y)
{
	mlx_image_t	*image;
	t_vector2	position;

	image = get_roof_top_corner_image(gc, map_x, map_y);
	position = map_to_world_position_xy(map_x, map_y - 1);
	return (mlx_image_to_window(gc->mlx, image, position.x, position.y) != -1);
}

static bool	place_roof_tile(t_context *gc, int x, int y)
{
	if (is_top_wall(gc->map, x, y))
	{
		return (place_roof_on_wall(gc, x, y));
	}			
	else
	{
		if (!place_roof_without_wall(gc, x, y))
			return (false);
		if (is_top_corner(gc->map, x, y))
		{
			if (!place_roof_top_corner(gc, x, y))
				return (false);
		}	
	}
	return (true);
}

bool	load_roofs(t_context *gc)
{
	char **const	map = gc->map->data;
	int				x;
	int				y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == MAP_WALL)
			{
				if (!place_roof_tile(gc, x, y))
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}
