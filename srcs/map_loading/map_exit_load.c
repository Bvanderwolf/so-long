/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_exit_load.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 15:04:10 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:48:09 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_utils.h"
#include "so_long_img.h"
#include "so_long_map.h"
#include <stdbool.h>

// Note to self: for now it always places an exit. in the future
// should place doors as well if a wall is above.
static bool	place_exit_tile(t_context *gc, int map_x, int map_y)
{
	t_image		*image;
	t_vector2	world_position;

	image = find_image(gc->images, IMG_EXIT);
	world_position = map_to_world_position_xy(map_x, map_y);
	return (mlx_image_to_window(gc->mlx,
			image->value,
			world_position.x,
			world_position.y
		) != -1);
}

bool	load_exit(t_context *gc)
{
	t_vector2	position;

	position = find_map_position(gc->map->data, MAP_EXIT);
	return (place_exit_tile(gc, position.x, position.y));
}
