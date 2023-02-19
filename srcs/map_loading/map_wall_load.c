/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_wall_load.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 15:00:51 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:47:40 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_utils.h"
#include "so_long_img.h"
#include "so_long_map.h"
#include <stdbool.h>

static bool	place_wall_image(t_context *gc, int map_x, int map_y)
{
	t_image		*image;
	t_vector2	world_position;

	image = find_image(gc->images, IMG_WALL);
	world_position = map_to_world_position_xy(map_x, map_y);
	return (mlx_image_to_window(gc->mlx,
			image->value,
			world_position.x,
			world_position.y
		) != -1);
}

bool	load_walls(t_context *gc)
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
			if (data[y][x] == MAP_WALL && is_top_wall(gc->map, x, y)
				&& !place_wall_image(gc, x, y))
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}
