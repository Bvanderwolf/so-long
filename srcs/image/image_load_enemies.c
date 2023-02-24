/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_load_enemies.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 14:17:50 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 12:39:13 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "so_long.h"
#include "so_long_img.h"

bool	img_load_goblin(t_context *gc)
{
	const char		*paths[] = {
		"textures/goblin_idle_right.png",
		"textures/goblin_idle_left.png",
		"textures/goblin_run_right.png",
		"textures/goblin_run_left.png",
		NULL
	};

	return (load_sheets_at_paths(gc, paths, DEFAULT_ANIM_LEN));
}

bool	img_load_slime(t_context *gc)
{
	const char		*paths[] = {
		"textures/slime_idle_right.png",
		"textures/slime_idle_left.png",
		"textures/slime_run_right.png",
		"textures/slime_run_left.png",
		NULL
	};

	return (load_sheets_at_paths(gc, paths, DEFAULT_ANIM_LEN));
}

bool	img_load_flying_enemy(t_context *gc)
{
	const char		*paths[] = {
		"textures/fly_idle_right.png",
		"textures/fly_idle_left.png",
		"textures/fly_run_right.png",
		"textures/fly_run_left.png",
		NULL
	};

	return (load_sheets_at_paths(gc, paths, SHORT_ANIM_LEN));
}

bool	load_enemy_images(t_context *gc)
{
	return (img_load_goblin(gc)
		&& img_load_slime(gc)
		&& img_load_flying_enemy(gc));
}
