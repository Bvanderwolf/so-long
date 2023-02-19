/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_floor_load.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 14:58:30 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:47:33 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_utils.h"
#include "so_long_img.h"
#include "so_long_map.h"
#include <stdbool.h>
#include <stdlib.h>

static void	get_random_default_floor_image_name(char *name_buffer)
{
	float perc;

	perc = rand01();
	if (perc < 0.15f)
		ft_strcpy(name_buffer, IMG_FLOOR);
	else if (perc < 0.3f)
		ft_strcpy(name_buffer, IMG_FLOOR_ONE);
	else if (perc < 0.45f)
		ft_strcpy(name_buffer, IMG_FLOOR_TWO);
	else if (perc < 0.6f)
		ft_strcpy(name_buffer, IMG_FLOOR_THREE);
	else if (perc < 0.7f)
		ft_strcpy(name_buffer, IMG_FLOOR_FOUR);
	else if (perc < 0.8f)
		ft_strcpy(name_buffer, IMG_FLOOR_FIVE);
	else if (perc < 0.9f)
		ft_strcpy(name_buffer, IMG_FLOOR_SIX);
	else
		ft_strcpy(name_buffer, IMG_FLOOR_SEVEN);
}

static t_image	*find_floor_image(t_context *gc, int map_x, int map_y)
{
	char	default_floor_name[MAX_IMG_NAME_SIZE];

	if (map_x == 1 && map_y == 1)
		return (find_image(gc->images, IMG_FLOOR_TOP_LEFT));
	if (map_x == gc->map->width - 2 && map_y == 1)
		return (find_image(gc->images, IMG_FLOOR_TOP_RIGHT));
	if (map_x > 1 && map_x < gc->map->width - 1 && map_y == 1)
		return (find_image(gc->images, IMG_FLOOR_TOP));
	if (map_x == 1 && map_y > 1 && map_y < gc->map->height - 1)
		return (find_image(gc->images, IMG_FLOOR_LEFT));
	if (map_x == gc->map->width - 2 && map_x > 1 && map_x < gc->map->width - 1)
		return (find_image(gc->images, IMG_FLOOR_RIGHT));
	get_random_default_floor_image_name(default_floor_name);
	return (find_image(gc->images, default_floor_name));
}

static bool	place_floor_tile(t_context *gc, int map_x, int map_y)
{
	t_image		*image;
	t_vector2	world_position;

	image = find_floor_image(gc, map_x, map_y);
	world_position = map_to_world_position_xy(map_x, map_y);
	return (mlx_image_to_window(gc->mlx,
			image->value,
			world_position.x,
			world_position.y
		) != -1);
}

bool	load_floor(t_context *gc)
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
			if (ft_strchr(FLOOR_CHARS, data[y][x]) != NULL
				|| (is_map_wall(data, x, y) && !is_outer_wall(gc->map, x, y)))
			{
				if (!place_floor_tile(gc, x, y))
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}
