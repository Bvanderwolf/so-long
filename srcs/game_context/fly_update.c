/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fly_update.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 12:51:19 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 11:22:00 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_anim.h"
#include "ft_printf.h"
#include "so_long_map.h"

static void	reset_fly_walk_to_idle(t_enemy *fly)
{
	const char	prefix[] = "fly_idle";
	char		name[MAX_IMG_NAME_SIZE + 1];

	animation_disable(get_active_animation(fly->animatable->animations));
	append_animation_suffix(fly->look_direction, prefix, name);
	set_active_animation(&(fly->animatable->animations), name);
}

static void	update_fly_walk_decision(t_context *gc, int map_x, int map_y)
{
	t_enemy		*fly;
	t_vector2	direction;
	t_vector2	spawn_map_xy;

	spawn_map_xy = vector2_new(map_x, map_y);
	fly = get_enemy(gc, spawn_map_xy);
	if (walk_is_active(fly->walk))
		return ;
	fly->current_decision_time += gc->mlx->delta_time;
	if (fly->current_decision_time < fly->decision_time)
		return ;
	fly->current_decision_time = 0.0;
	direction = get_random_direction_walls_ignored(gc->map, fly->map_xy);
	if (is_invalid_direction(direction)
		|| walks_into_enemy(gc, fly->world_xy, direction))
		return ;
	walk_set_target(fly->walk, direction, fly->world_xy);
	if (vector2_equals_xy(direction, 1, 0)
		|| vector2_equals_xy(direction, -1, 0))
			fly->look_direction = direction;
}

static void	update_fly_world_position(t_enemy *fly)
{
	t_vector2		new_position;
	t_animation		*animation;
	t_list			*current_animation;

	new_position = vector2_add(fly->world_xy, fly->walk->direction);
	current_animation = fly->animatable->animations;
	while (current_animation != NULL)
	{
		animation = (t_animation *)current_animation->content;
		update_animation_position(animation, new_position);
		current_animation = current_animation->next;
	}
	fly->world_xy = new_position;
}

static void	update_fly_position(t_context *gc, int map_x, int map_y)
{
	t_enemy		*fly;
	t_vector2	spawn_map_xy;

	spawn_map_xy = vector2_new(map_x, map_y);
	fly = get_enemy(gc, spawn_map_xy);
	if (vector2_equals(fly->walk->target_world_xy, fly->world_xy))
	{
		if (walk_is_active(fly->walk))
		{
			fly->map_xy = world_to_map_position(fly->world_xy);
			fly->walk->direction = vector2_new(0, 0);
			reset_fly_walk_to_idle(fly);
		}
	}
	else
	{
		update_fly_world_position(fly);
	}
}

void	render_flies(void *context)
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
			if (data[y][x] == MAP_FLY)
			{
				update_fly_walk_decision(gc, x, y);
				update_fly_walk_animation(gc, x, y);
				render_fly_animation(gc, x, y);
				update_fly_position(gc, x, y);
			}
			x++;
		}
		y++;
	}
}
