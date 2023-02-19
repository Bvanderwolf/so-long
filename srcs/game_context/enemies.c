/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemies.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/11 12:19:51 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/11 16:30:27 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "so_long.h"
#include "so_long_anim.h"
#include "so_long_map.h"

// *Note to self: look_direction is now always vector2.right. this should be 
// based on the walls around the enemy.
t_enemy	*create_enemy(t_context *gc, t_vector2 map_xy, float decision_time, float animation_speed, const char *tex_names[])
{
	t_enemy			*enemy;
	t_animatable	*animatable;
	t_list			*animatable_item;

	enemy = (t_enemy *)malloc(sizeof(t_enemy));
	if (enemy == NULL)
		return (NULL);
	animatable = create_animatable(gc, map_xy, animation_speed, tex_names);
	if (animatable == NULL)
		return (free(enemy), NULL);
	animatable_item = ft_lstnew(animatable);
	if (animatable_item == NULL)
		return (free(enemy), free(animatable), NULL);
	enemy->walk = walk_alloc(enemy->world_xy);
	if (enemy->walk == NULL)
		return (free(enemy), free(animatable), NULL);
	enemy->animatable = animatable;
	ft_lstadd_back(&(gc->animatables), animatable_item);
	enemy->map_xy = map_xy;
	enemy->decision_time = decision_time;
	enemy->current_decision_time = 0.0;
	enemy->world_xy = map_to_world_position(map_xy);
	enemy->look_direction = vector2_new(1, 0);
	return (enemy);
}

t_enemy	*get_enemy(t_context *gc, t_vector2 spawn_map_xy)
{
	t_list			*current;
	t_animatable	*animatable;
	t_enemy			*enemy;

	animatable = get_animatable(gc, spawn_map_xy);
	current = gc->enemies;
	while (current != NULL)
	{
		enemy = (t_enemy *)current->content;
		if (enemy->animatable == animatable)
			return (enemy);
		current = current->next;
	}
	return (NULL);
}

bool	walks_into_enemy(t_context *gc, t_vector2 world_xy, t_vector2 direction)
{
	t_list			*current;
	t_enemy			*enemy;
	t_vector2		target_world_xy;

	target_world_xy.x = world_xy.x + (TILE_SIZE * direction.x);
	target_world_xy.y = world_xy.y + (TILE_SIZE * direction.y);
	current = gc->enemies;
	while (current != NULL)
	{
		enemy = (t_enemy *)current->content;
		if (vector2_equals(target_world_xy, enemy->world_xy)
			|| vector2_equals(target_world_xy, enemy->walk->target_world_xy))
			return (true);
		current = current->next;
	}
	return (false);
}

void	free_enemy(void *enemy)
{
	free(((t_enemy *)enemy)->walk);
	free(enemy);
}