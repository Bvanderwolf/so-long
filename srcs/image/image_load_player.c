/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_load_player.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 16:07:51 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:44:55 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "so_long.h"
#include "so_long_img.h"
#include "so_long_anim.h"
#include "so_long_utils.h"
#include "ft_printf.h"
#include "libft.h"
#include "MLX42/MLX42.h"

static bool	img_load_player_end(t_context *gc)
{
	const char	*paths[] = {
		"textures/player_end.png",
		NULL
	};

	return (load_sheets_at_paths(gc, paths, SHORT_ANIM_LEN));
}

static bool	img_load_player_walk(t_context *gc)
{
	const char	*paths[] = {
		"textures/knight_idle_right.png",
		"textures/knight_idle_left.png",
		"textures/knight_run_right.png",
		"textures/knight_run_left.png",
		NULL
	};

	return (load_sheets_at_paths(gc, paths, DEFAULT_ANIM_LEN));
}

bool	load_player_image(t_context *gc)
{
	return (img_load_player_walk(gc) && img_load_player_end(gc));
}
