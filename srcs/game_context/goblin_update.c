/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   goblin_update.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 18:36:30 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:59:48 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_anim.h"
#include "ft_printf.h"
#include "so_long_map.h"

static void	reset_goblin_walk_to_idle(t_enemy *goblin)
{
	const char	prefix[] = "goblin_idle";
	char		name[MAX_IMG_NAME_SIZE + 1];

	animation_disable(get_active_animation(goblin->animatable->animations));
	append_animation_suffix(goblin->look_direction, prefix, name);
	set_active_animation(&(goblin->animatable->animations), name);
}

static void	update_goblin_walk_decision(t_context *gc, int map_x, int map_y)
{
	t_enemy		*goblin;
	t_vector2	direction;
	t_vector2	spawn_map_xy;

	spawn_map_xy = vector2_new(map_x, map_y);
	goblin = get_enemy(gc, spawn_map_xy);
	if (walk_is_active(goblin->walk))
		return ;
	goblin->current_decision_time += gc->mlx->delta_time;
	if (goblin->current_decision_time < goblin->decision_time)
		return ;
	goblin->current_decision_time = 0.0;
	direction = get_random_direction(gc->map, goblin->map_xy);
	if (is_invalid_direction(direction) 
		|| walks_into_enemy(gc, goblin->world_xy, direction))
		return ;
	walk_set_target(goblin->walk, direction, goblin->world_xy);
	if (vector2_equals_xy(direction, 1, 0) || vector2_equals_xy(direction, -1, 0))
			goblin->look_direction = direction;
}

static void	update_goblin_walk_animation(t_context *gc, int map_x, int map_y)
{
	const char	run_prefix[] = "goblin_run";
	char		run_name[MAX_IMG_NAME_SIZE + 1];
	t_enemy		*goblin;
	t_animation		*active_anim;

	goblin = get_enemy(gc, vector2_new(map_x, map_y));
	if (!walk_is_active(goblin->walk))
		return ;
	active_anim = get_active_animation(goblin->animatable->animations);
	if (ft_strncmp(active_anim->name, run_prefix, sizeof(run_prefix) - 1) != 0)
	{
		animation_disable(active_anim);
		append_animation_suffix(goblin->look_direction, run_prefix, run_name);
		set_active_animation(&(goblin->animatable->animations), run_name);
	}
}

static void	render_goblin_animation(t_context *gc, int map_x, int map_y)
{
	t_animatable	*animatable;
	t_animation			*animation;

	animatable = get_animatable(gc, vector2_new(map_x, map_y));
	animation = get_active_animation(animatable->animations);
	update_animation_image(animation);
}

static void	update_goblin_world_position(t_enemy *goblin)
{
	t_vector2		new_position;
	t_animation			*animation;
	t_list			*current_animation;

	new_position = vector2_add(goblin->world_xy, goblin->walk->direction);
	current_animation = goblin->animatable->animations;
	while (current_animation != NULL)
	{
		animation = (t_animation *)current_animation->content;
		update_animation_position(animation, new_position);
		current_animation = current_animation->next;
	}
	goblin->world_xy = new_position;
}

static void	update_goblin_position(t_context *gc, int map_x, int map_y)
{
	t_enemy		*goblin;
	t_vector2	spawn_map_xy;

	spawn_map_xy = vector2_new(map_x, map_y);
	goblin = get_enemy(gc, spawn_map_xy);
	if (vector2_equals(goblin->walk->target_world_xy, goblin->world_xy))
	{
		if (walk_is_active(goblin->walk))
		{
			goblin->map_xy = world_to_map_position(goblin->world_xy);
			goblin->walk->direction = vector2_new(0, 0);
			reset_goblin_walk_to_idle(goblin);
		}
	}
	else
	{
		update_goblin_world_position(goblin);
	}
}

void	render_goblins(void *context)
{
	t_context *const	gc = context;
	char **const		data = gc->map->data;
	int					x;
	int					y;

	y = 0;
	while (data[y] != NULL)
	{
		x = 0;
		while (data[y][x] != '\0')
		{
			if (data[y][x] == MAP_GOBLIN)
			{
				update_goblin_walk_decision(gc, x, y);
				update_goblin_walk_animation(gc, x, y);
				render_goblin_animation(gc, x, y);
				update_goblin_position(gc, x, y);
			}
			x++;
		}
		y++;
	}
}
