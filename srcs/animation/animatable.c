/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animatable.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 10:47:04 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 11:06:45 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_anim.h"
#include <stdlib.h>
#include "so_long.h"
#include "so_long_utils.h"

void	render_animatable(void *context)
{
	t_animatable *const	animatable = context;
	t_animation			*animation;

	animation = get_active_animation(animatable->animations);
	update_animation_image(animation);
}

t_animatable	*get_animatable(t_context *gc, t_vector2 spawn_map_xy)
{
	t_list			*current;
	t_animatable	*animatable;

	current = gc->animatables;
	while (current != NULL)
	{
		animatable = (t_animatable *)current->content;
		if (vector2_equals(animatable->spawn_map_xy, spawn_map_xy))
			return (animatable);
		current = current->next;
	}
	return (NULL);
}

t_animatable	*create_animatable(t_context *gc, t_vector2 map_xy, \
float speed, const char *paths[])
{
	t_animatable	*animatable;

	animatable = (t_animatable *)malloc(sizeof(t_animatable));
	if (animatable == NULL)
		return (NULL);
	animatable->spawn_map_xy = map_xy;
	animatable->animations = create_animations(gc, paths, speed);
	if (animatable->animations == NULL)
		return (free(animatable), NULL);
	return (animatable);
}

void	free_animatable(void *animatable)
{
	ft_lstclear(&(((t_animatable *)animatable)->animations), &free);
	free(animatable);
}
