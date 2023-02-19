/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_load.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 15:12:50 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:53:41 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "so_long.h"
#include "so_long_utils.h"
#include "so_long_img.h"
#include "so_long_anim.h"
#include "so_long_map.h"
#include "MLX42/MLX42.h"

#include <stdio.h>

// *Note to self: look_direction is now always vector2.right. this should be 
// based on the walls around the player.
static bool	alloc_fields(t_context *gc, t_player *player, t_vector2 position)
{
	const char	*tex_names[] = {
		"knight_idle_right.png", "knight_idle_left.png",
		"knight_run_right.png", "knight_run_left.png",
		NULL
	};

	player->map_xy = world_to_map_position(position);
	player->world_xy = position;
	player->look_direction = vector2_new(1, 0);
	player->walk = walk_alloc(position);
	player->target_walk = walk_alloc(position);
	if (player->walk == NULL)
		return (false);
	player->animations = create_animations(gc, tex_names, DEFAULT_ANIM_SPEED);
	if (player->animations == NULL)
		return (false);
	gc->player = player;
	return (true);
}

static bool	push_player_to_window(t_context *gc, t_player *player)
{
	int32_t	xy[2];

	xy[0] = player->world_xy.x;
	xy[1] = player->world_xy.y;
	if (!animations_to_window(gc->mlx, player->animations, xy))
		return (false);
	if (!mlx_loop_hook(gc->mlx, &render_player, gc))
		return (false);
	if (!player_collision_hook(gc, &handle_player_collision))
		return (false);
	if (!player_position_hook(gc, &update_player_steps_ui)
		|| !player_position_hook(gc, &check_game_completion))
		return (false);
	mlx_key_hook(gc->mlx, &handle_player_input, gc);
	return (true);
}

bool	load_player(t_context *gc, t_vector2 world_position)
{
	t_player	*player;

	player = (t_player *)ft_calloc(1, sizeof(t_player));
	if (player == NULL)
		return (false);
	if (!alloc_fields(gc, player, world_position))
		return (false);
	if (!push_player_to_window(gc, player))
		return (false);
	return (true);
}

void	unload_player(t_context *gc)
{
	ft_lstclear(&gc->player->animations, &free);
	free(gc->player->target_walk);
	free(gc->player->walk);
	free(gc->player);
}
