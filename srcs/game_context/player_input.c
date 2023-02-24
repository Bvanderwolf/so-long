/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_input.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 14:57:52 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 11:58:19 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_utils.h"
#include "so_long_map.h"
#include <stdbool.h>
#include <stdio.h>

static void	handle_follow_up_walk(t_context *gc, t_walk *walk, \
t_walk *target_walk, t_vector2 walk_direction)
{
	t_vector2	target_map_xy;

	target_map_xy = world_to_map_position(walk->target_world_xy);
	if (walks_into_wall(gc, target_map_xy, walk_direction)
		|| walks_into_closed_exit(gc, target_map_xy, walk_direction))
		return ;
	if (vector2_equals(target_walk->target_world_xy, walk->target_world_xy))
		walk_set_target(target_walk, walk_direction, walk->target_world_xy);
}

static void	handle_movement_input(t_context *gc, mlx_key_data_t keydata)
{
	t_walk *const	walk = gc->player->walk;
	t_walk *const	target_walk = gc->player->target_walk;
	t_vector2		walk_direction;

	if (gc->completed)
		return ;
	walk_direction = get_walk_direction_from_input(keydata);
	if (is_invalid_direction(walk_direction))
		return ;
	if (walk_is_active(walk))
	{
		handle_follow_up_walk(gc, walk, target_walk, walk_direction);
	}
	else
	{
		if (walks_into_wall(gc, gc->player->map_xy, walk_direction)
			|| walks_into_closed_exit(gc, gc->player->map_xy, walk_direction))
			return ;
		walk_set_target(walk, walk_direction, gc->player->world_xy);
		walk_set_target(target_walk, walk_direction, gc->player->world_xy);
		if (vector2_equals_xy(walk_direction, 1, 0)
			|| vector2_equals_xy(walk_direction, -1, 0))
			gc->player->look_direction = walk_direction;
	}
}

static void	handle_exit_input(mlx_t *mlx, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);
}

void	handle_player_input(mlx_key_data_t keydata, void *context)
{
	t_context *const	gc = context;

	handle_movement_input(gc, keydata);
	handle_exit_input(gc->mlx, keydata);
}
