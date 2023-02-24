/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_enemy_collision.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/12 10:36:07 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 12:31:43 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_anim.h"
#include "so_long_utils.h"

void	update_player_enemy_collision(t_context *gc)
{
	const int		min_distance_sqrd = TILE_SIZE * TILE_SIZE / 3;
	t_list			*current_enemy;
	t_player *const	p = gc->player;
	t_enemy			*e;

	current_enemy = gc->enemies;
	while (current_enemy != NULL)
	{
		e = (t_enemy *)current_enemy->content;
		if (vector2_sqr_distance(e->world_xy, p->world_xy) < min_distance_sqrd)
		{	
			invoke_player_collision(ENEMY_COLLISION, gc);
			break ;
		}
		current_enemy = current_enemy->next;
	}
}
