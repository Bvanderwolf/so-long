/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_torch_load.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/28 11:06:16 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 14:08:32 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "so_long.h"
#include "so_long_map.h"
#include "ft_printf.h"
#include "so_long_anim.h"

static bool	place_torch(t_context *gc, int map_x, int map_y)
{
	const char		*tex_names[] = {"torch_light.png", NULL};
	t_animatable	*animatable;
	t_list			*animatable_item;
	int32_t			xy[2];
	t_vector2		world_position;

	animatable = create_animatable(gc,
			vector2_new(map_x, map_y),
			rand_minmax(0.8f, 1.0f),
			tex_names);
	if (animatable == NULL)
		return (false);
	animatable_item = ft_lstnew(animatable);
	if (animatable_item == NULL)
		return (free(animatable), false);
	ft_lstadd_back(&(gc->animatables), animatable_item);
	world_position = map_to_world_position_xy(map_x, map_y);
	xy[0] = world_position.x;
	xy[1] = world_position.y;
	if (!animations_to_window(gc->mlx, animatable->animations, xy))
		return (false);
	if (!mlx_loop_hook(gc->mlx, &render_animatable, animatable))
		return (false);
	return (true);
}

bool	load_torch_props(t_context *gc)
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
			if (is_map_wall(data, x, y) && is_torch(gc->map, x, y))
			{
				if (!place_torch(gc, x, y))
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}
