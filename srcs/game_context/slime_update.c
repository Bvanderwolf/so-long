/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   slime_update.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 12:06:29 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 12:02:04 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_anim.h"
#include "ft_printf.h"
#include "so_long_map.h"

static void	reset_slime_walk_to_idle(t_enemy *slime)
{
	const char	prefix[] = "slime_idle";
	char		name[MAX_IMG_NAME_SIZE + 1];

	animation_disable(get_active_animation(slime->animatable->animations));
	append_animation_suffix(slime->look_direction, prefix, name);
	set_active_animation(&(slime->animatable->animations), name);
}

static void	update_slime_walk_decision(t_context *gc, int map_x, int map_y)
{
	t_enemy		*slime;
	t_vector2	direction;
	t_vector2	spawn_map_xy;

	spawn_map_xy = vector2_new(map_x, map_y);
	slime = get_enemy(gc, spawn_map_xy);
	if (walk_is_active(slime->walk))
		return ;
	slime->current_decision_time += gc->mlx->delta_time;
	if (slime->current_decision_time < slime->decision_time)
		return ;
	slime->current_decision_time = 0.0;
	direction = get_random_direction(gc->map, slime->map_xy);
	if (is_invalid_direction(direction)
		|| walks_into_enemy(gc, slime->world_xy, direction))
		return ;
	walk_set_target(slime->walk, direction, slime->world_xy);
	if (vector2_equals_xy(direction, 1, 0)
		|| vector2_equals_xy(direction, -1, 0))
			slime->look_direction = direction;
}

static void	update_slime_world_position(t_enemy *slime)
{
	t_vector2		new_position;
	t_animation		*animation;
	t_list			*current_animation;

	new_position = vector2_add(slime->world_xy, slime->walk->direction);
	current_animation = slime->animatable->animations;
	while (current_animation != NULL)
	{
		animation = (t_animation *)current_animation->content;
		update_animation_position(animation, new_position);
		current_animation = current_animation->next;
	}
	slime->world_xy = new_position;
}

static void	update_slime_position(t_context *gc, int map_x, int map_y)
{
	t_enemy		*slime;
	t_vector2	spawn_map_xy;

	spawn_map_xy = vector2_new(map_x, map_y);
	slime = get_enemy(gc, spawn_map_xy);
	if (vector2_equals(slime->walk->target_world_xy, slime->world_xy))
	{
		if (walk_is_active(slime->walk))
		{
			slime->map_xy = world_to_map_position(slime->world_xy);
			slime->walk->direction = vector2_new(0, 0);
			reset_slime_walk_to_idle(slime);
		}
	}
	else
	{
		update_slime_world_position(slime);
	}
}

void	render_slimes(void *context)
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
			if (data[y][x] == MAP_SLIME)
			{
				update_slime_walk_decision(gc, x, y);
				update_slime_walk_animation(gc, x, y);
				render_slime_animation(gc, x, y);
				update_slime_position(gc, x, y);
			}
			x++;
		}
		y++;
	}
}
