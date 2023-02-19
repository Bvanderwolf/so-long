/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_collectable_load.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 15:02:55 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:48:02 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_utils.h"
#include "so_long_img.h"
#include "so_long_map.h"
#include <stdbool.h>

static t_image	*get_collectable_image(t_context *gc)
{
	if (gc->collectables == 1)
		return (find_image(gc->images, IMG_KEY));
	return (find_image(gc->images, IMG_GOLD));
}

static bool	place_collectable(t_context *gc, int map_x, int map_y)
{
	t_image		*image;
	t_vector2	world_position;

	gc->collectables++;
	image = get_collectable_image(gc);
	world_position = map_to_world_position_xy(map_x, map_y);
	return (mlx_image_to_window(gc->mlx,
			image->value,
			world_position.x,
			world_position.y
		) != -1);
}

bool	load_collectables(t_context *gc)
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
			if (data[y][x] == MAP_COLLECTABLE && !place_collectable(gc, x, y))
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}
