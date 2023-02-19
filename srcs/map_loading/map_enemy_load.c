/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_enemy_load.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 17:25:22 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:48:31 by bvan-der      ########   odam.nl         */
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
	const char		*tex_names[] = { 
		"slime_idle_right.png", "slime_idle_left.png",
		"slime_run_right.png", "slime_run_left.png",
		NULL
	};
	t_enemy			*slime;
	t_list			*enemy;
	int32_t			xy[2];
	t_vector2		world_position;
	float			decision_time;

	decision_time = rand_minmax(MIN_SLIME_DECISION_TIME, MAX_SLIME_DECISION_TIME);
	slime = create_enemy(gc, vector2_new(map_x, map_y), decision_time, DEFAULT_ANIM_SPEED, tex_names);
	if (slime == NULL)
		return (false);
	enemy = ft_lstnew(slime);
	if (enemy == NULL)
		return (free(slime), NULL);
	ft_lstadd_back(&(gc->enemies), enemy);
	world_position = map_to_world_position_xy(map_x, map_y);
	xy[0] = world_position.x;
	xy[1] = world_position.y;
	if (!animations_to_window(gc->mlx, slime->animatable->animations, xy))
		return (false);
	return (true);
}

static bool	place_goblin(t_context *gc, int map_x, int map_y)
{
	const char		*tex_names[] = { 
		"goblin_idle_right.png", "goblin_idle_left.png",
		"goblin_run_right.png", "goblin_run_left.png",
		NULL
	};
	t_enemy			*goblin;
	t_list			*enemy;
	int32_t			xy[2];
	t_vector2		world_position;
	float			decision_time;

	decision_time = rand_minmax(MIN_GOBLIN_DECISION_TIME, MAX_GOBLIN_DECISION_TIME);
	goblin = create_enemy(gc, vector2_new(map_x, map_y), decision_time, DEFAULT_ANIM_SPEED, tex_names);
	if (goblin == NULL)
		return (false);
	enemy = ft_lstnew(goblin);
	if (enemy == NULL)
		return (free(goblin), NULL);
	ft_lstadd_back(&(gc->enemies), enemy);
	world_position = map_to_world_position_xy(map_x, map_y);
	xy[0] = world_position.x;
	xy[1] = world_position.y;
	if (!animations_to_window(gc->mlx, goblin->animatable->animations, xy))
		return (false);
	return (true);
}

static bool	place_fly(t_context *gc, int map_x, int map_y)
{
	const char		*tex_names[] = { 
		"fly_idle_right.png", "fly_idle_left.png",
		"fly_run_right.png", "fly_run_left.png",
		NULL
	};
	t_enemy			*fly;
	t_list			*enemy;
	int32_t			xy[2];
	t_vector2		world_position;
	float			decision_time;

	decision_time = rand_minmax(MIN_FLY_DECISION_TIME, MAX_FLY_DECISION_TIME);
	fly = create_enemy(gc, vector2_new(map_x, map_y), decision_time, DEFAULT_ANIM_SPEED, tex_names);
	if (fly == NULL)
		return (false);
	enemy = ft_lstnew(fly);
	if (enemy == NULL)
		return (free(fly), NULL);
	ft_lstadd_back(&(gc->enemies), enemy);
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
	int	x;
	int	y;

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