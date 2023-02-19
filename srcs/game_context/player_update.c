/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_update.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 16:38:04 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:59:48 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "so_long.h"
#include "so_long_anim.h"
#include "so_long_utils.h"
#include "so_long_map.h"
#include "ft_printf.h"

static void	update_player_walk_animation(t_player *player)
{
	const char	run_prefix[] = "knight_run";
	char		run_name[MAX_IMG_NAME_SIZE + 1];
	t_animation		*active_anim;

	if (!walk_is_active(player->walk))
		return ;
	active_anim = get_active_animation(player->animations);
	if (ft_strncmp(active_anim->name, run_prefix, sizeof(run_prefix) - 1) != 0)
	{
		animation_disable(active_anim);
		append_animation_suffix(player->look_direction, run_prefix, run_name);
		set_active_animation(&player->animations, run_name);
	}
}

static void	render_player_animation(t_player *player)
{
	t_animation	*animation;

	animation = get_active_animation(player->animations);
	update_animation_image(animation);
}

void	render_player(void *context)
{
	t_context *const	gc = context;

	if (gc->completed)
		return ;
	update_player_walk_animation(gc->player);
	render_player_animation(gc->player);
	update_player_position(gc);
	update_player_collectables(gc);
	update_player_enemy_collision(gc);
}
