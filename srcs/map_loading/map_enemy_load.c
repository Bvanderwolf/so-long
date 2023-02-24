/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_enemy_load.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 17:25:22 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 14:33:05 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "so_long.h"
#include "so_long_anim.h"
#include "so_long_map.h"
#include "ft_printf.h"
#include "stdio.h"

static bool	place_slime(t_context *gc, int map_x, int map_y)
{
	t_enemy			*slime;
	int32_t			xy[2];
	t_vector2		world_position;

	slime = load_slime(gc, map_x, map_y);
	if (slime == NULL)
		return (NULL);
	world_position = map_to_world_position_xy(map_x, map_y);
	xy[0] = world_position.x;
	xy[1] = world_position.y;
	if (!animations_to_window(gc->mlx, slime->animatable->animations, xy))
		return (false);
	return (true);
}

static bool	place_goblin(t_context *gc, int map_x, int map_y)
{
	t_enemy			*goblin;
	int32_t			xy[2];
	t_vector2		world_position;

	goblin = load_goblin(gc, map_x, map_y);
	if (goblin == NULL)
		return (NULL);
	world_position = map_to_world_position_xy(map_x, map_y);
	xy[0] = world_position.x;
	xy[1] = world_position.y;
	if (!animations_to_window(gc->mlx, goblin->animatable->animations, xy))
		return (false);
	return (true);
}

static bool	place_fly(t_context *gc, int map_x, int map_y)
{
	t_enemy			*fly;
	int32_t			xy[2];
	t_vector2		world_position;

	fly = load_fly(gc, map_x, map_y);
	if (fly == NULL)
		return (NULL);
	world_position = map_to_world_position_xy(map_x, map_y);
	xy[0] = world_position.x;
	xy[1] = world_position.y;
	if (!animations_to_window(gc->mlx, fly->animatable->animations, xy))
		return (false);
	return (true);
}

static bool	place_enemies_on_map(t_context *gc)
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
			if (map[y][x] == MAP_GOBLIN && !place_goblin(gc, x, y))
				return (false);
			else if (map[y][x] == MAP_SLIME && !place_slime(gc, x, y))
				return (false);
			else if (map[y][x] == MAP_FLY && !place_fly(gc, x, y))
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

bool	load_enemies(t_context *gc)
{
	if (!place_enemies_on_map(gc))
		return (false);
	if (!mlx_loop_hook(gc->mlx, &render_goblins, gc))
		return (false);
	if (!mlx_loop_hook(gc->mlx, &render_slimes, gc))
		return (false);
	if (!mlx_loop_hook(gc->mlx, &render_flies, gc))
		return (false);
	return (true);
}
