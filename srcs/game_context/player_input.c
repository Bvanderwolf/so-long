/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_input.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 14:57:52 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 16:00:07 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_utils.h"
#include "so_long_map.h"
#include <stdbool.h>
#include <stdio.h>

#include "ft_printf.h"

static bool	is_key_pressed(t_keyinput key, mlx_key_data_t data)
{
	if (key == KEY_UP)
		return (data.key == MLX_KEY_W || data.key == MLX_KEY_UP);
	if (key == KEY_LEFT)
		return (data.key == MLX_KEY_A || data.key == MLX_KEY_LEFT);
	if (key == KEY_DOWN)
		return (data.key == MLX_KEY_S || data.key == MLX_KEY_DOWN);
	if (key == KEY_RIGHT)
		return (data.key == MLX_KEY_D || data.key == MLX_KEY_RIGHT);
	return (false);
}

static t_vector2	get_walk_direction_from_input(mlx_key_data_t data)
{
	if (is_key_pressed(KEY_RIGHT, data) && data.action != MLX_PRESS)
		return (vector2_new(1, 0));
	if (is_key_pressed(KEY_LEFT, data) && data.action != MLX_PRESS)
		return (vector2_new(-1, 0));
	if (is_key_pressed(KEY_DOWN, data) && data.action != MLX_PRESS)
		return (vector2_new(0, 1));
	if (is_key_pressed(KEY_UP, data) && data.action != MLX_PRESS)
		return (vector2_new(0, -1));
	return (vector2_new(0, 0));
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
		if (walks_into_wall(gc, world_to_map_position(walk->target_world_xy), walk_direction)
			|| walks_into_closed_exit(gc, world_to_map_position(walk->target_world_xy), walk_direction))
			return ;
		if (vector2_equals(target_walk->target_world_xy, walk->target_world_xy))
			walk_set_target(target_walk, walk_direction, walk->target_world_xy);
	}
	else
	{
		if (walks_into_wall(gc, gc->player->map_xy, walk_direction)
			|| walks_into_closed_exit(gc, gc->player->map_xy, walk_direction))
			return ;
		walk_set_target(walk, walk_direction, gc->player->world_xy);
		walk_set_target(target_walk, walk_direction, gc->player->world_xy);
		if (vector2_equals_xy(walk_direction, 1, 0) || vector2_equals_xy(walk_direction, -1, 0))
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
