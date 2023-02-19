/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_movement.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 11:32:10 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:59:48 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_anim.h"
#include "so_long_map.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

static void	reset_player_walk_to_idle(t_player *player)
{
	const char	prefix[] = "knight_idle";
	char		name[MAX_IMG_NAME_SIZE + 1];

	animation_disable(get_active_animation(player->animations));
	append_animation_suffix(player->look_direction, prefix, name);
	set_active_animation(&player->animations, name);
}

void	invoke_player_position_update(t_context *gc)
{
	t_list	*current;

	current = gc->position_hooks;
	while (current != NULL)
	{
		((t_position_hook)current->content)(gc);
		current = current->next;
	}
}

// adds a hook to the player map position update returning the game context.
bool	player_position_hook(t_context *gc, t_position_hook hook)
{
	t_list	*hook_item;

	hook_item = ft_lstnew(hook);
	if (hook_item == NULL)
		return (perror("failed adding position hook"), false);
	ft_lstadd_back(&(gc->position_hooks), hook_item);
	return (true);
}

static void	update_player_world_position(t_player *player)
{
	t_vector2		new_position;
	t_animation			*animation;
	t_list			*current_animation;

	new_position = vector2_add(player->world_xy, player->walk->direction);
	current_animation = player->animations;
	while (current_animation != NULL)
	{
		animation = (t_animation *)current_animation->content;
		update_animation_position(animation, new_position);
		current_animation = current_animation->next;
	}
	player->world_xy = new_position;
}

void	update_player_position(t_context *gc)
{
	t_player *const	player = gc->player;
	t_walk *const	walk = gc->player->walk;
	t_walk *const	target_walk = gc->player->target_walk;

	if (vector2_equals(walk->target_world_xy, player->world_xy))
	{
		if (walk_is_active(walk))
		{
			player->map_xy = world_to_map_position(player->world_xy);
			player->steps++;
			player->walk->direction = vector2_new(0, 0);
			reset_player_walk_to_idle(player);
			invoke_player_position_update(gc);
			if (!gc->completed && !vector2_equals(target_walk->target_world_xy, walk->target_world_xy))
			{
				walk_set_target(walk, target_walk->direction, gc->player->world_xy);
				if (vector2_equals_xy(target_walk->direction, 1, 0) || vector2_equals_xy(target_walk->direction, -1, 0))
					gc->player->look_direction = target_walk->direction;
			}
		}
	}
	else
	{
		update_player_world_position(player);
	}
}
