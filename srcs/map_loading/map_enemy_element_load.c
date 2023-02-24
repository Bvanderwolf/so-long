/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_enemy_element_load.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 14:28:59 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 14:32:48 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "so_long.h"
#include "so_long_anim.h"
#include "so_long_map.h"
#include "ft_printf.h"
#include "stdio.h"

t_enemy	*load_slime(t_context *gc, int map_x, int map_y)
{
	const char		*tex_names[] = {
		"slime_idle_right.png", "slime_idle_left.png",
		"slime_run_right.png", "slime_run_left.png",
		NULL
	};
	t_enemy			*slime;
	t_list			*enemy;
	t_animatable	*animatable;
	t_vector2		map_xy;

	map_xy = vector2_new(map_x, map_y);
	animatable = create_animatable(gc, map_xy, DEFAULT_ANIM_SPEED, tex_names);
	if (animatable == NULL)
		return (NULL);
	slime = create_enemy(gc, map_xy, animatable, rand_minmax(
				MIN_SLIME_DECISION_TIME,
				MAX_SLIME_DECISION_TIME));
	if (slime == NULL)
		return (free(animatable), NULL);
	enemy = ft_lstnew(slime);
	if (enemy == NULL)
		return (free(animatable), free(slime), NULL);
	ft_lstadd_back(&(gc->enemies), enemy);
	return (slime);
}

t_enemy	*load_goblin(t_context *gc, int map_x, int map_y)
{
	const char		*tex_names[] = {
		"goblin_idle_right.png", "goblin_idle_left.png",
		"goblin_run_right.png", "goblin_run_left.png",
		NULL
	};
	t_enemy			*goblin;
	t_list			*enemy;
	t_animatable	*animatable;
	t_vector2		map_xy;

	map_xy = vector2_new(map_x, map_y);
	animatable = create_animatable(gc, map_xy, DEFAULT_ANIM_SPEED, tex_names);
	if (animatable == NULL)
		return (NULL);
	goblin = create_enemy(gc, map_xy, animatable, rand_minmax(
				MIN_GOBLIN_DECISION_TIME,
				MAX_GOBLIN_DECISION_TIME));
	if (goblin == NULL)
		return (free(animatable), NULL);
	enemy = ft_lstnew(goblin);
	if (enemy == NULL)
		return (free(animatable), free(goblin), NULL);
	ft_lstadd_back(&(gc->enemies), enemy);
	return (goblin);
}

t_enemy	*load_fly(t_context *gc, int map_x, int map_y)
{
	const char		*tex_names[] = {
		"fly_idle_right.png", "fly_idle_left.png",
		"fly_run_right.png", "fly_run_left.png",
		NULL
	};
	t_enemy			*fly;
	t_list			*enemy;
	t_animatable	*animatable;
	t_vector2		map_xy;

	map_xy = vector2_new(map_x, map_y);
	animatable = create_animatable(gc, map_xy, DEFAULT_ANIM_SPEED, tex_names);
	if (animatable == NULL)
		return (NULL);
	fly = create_enemy(gc, map_xy, animatable, rand_minmax(
				MIN_FLY_DECISION_TIME,
				MAX_FLY_DECISION_TIME));
	if (fly == NULL)
		return (free(animatable), NULL);
	enemy = ft_lstnew(fly);
	if (enemy == NULL)
		return (free(animatable), free(fly), NULL);
	ft_lstadd_back(&(gc->enemies), enemy);
	return (fly);
}
