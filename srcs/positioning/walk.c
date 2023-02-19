/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   walk.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/07 12:39:31 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/09 13:27:19 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_anim.h"
#include "so_long_utils.h"
#include <stdio.h>

t_walk	*walk_alloc(t_vector2 target)
{
	t_walk	*walk;

	walk = (t_walk *)malloc(sizeof(t_walk));
	if (walk == NULL)
		return (NULL);
	walk->target_world_xy = target;
	walk->direction = vector2_new(0, 0);
	return (walk);
}

bool	walk_is_active(t_walk *walk)
{
	return (walk->direction.x != 0 || walk->direction.y != 0);
}

void	walk_set_target(t_walk *walk, t_vector2 direction, t_vector2 from)
{
	t_vector2	new_target_position;

	new_target_position.x = from.x + (TILE_SIZE * direction.x);
	new_target_position.y = from.y + (TILE_SIZE * direction.y);
	walk->target_world_xy = new_target_position;
	walk->direction = direction;
}
