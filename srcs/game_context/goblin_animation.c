/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   goblin_animation.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 11:23:54 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 11:25:14 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_anim.h"
#include "ft_printf.h"
#include "so_long_map.h"

void	update_goblin_walk_animation(t_context *gc, int map_x, int map_y)
{
	const char		run_prefix[] = "goblin_run";
	char			run_name[MAX_IMG_NAME_SIZE + 1];
	t_enemy			*goblin;
	t_animation		*active_anim;

	goblin = get_enemy(gc, vector2_new(map_x, map_y));
	if (!walk_is_active(goblin->walk))
		return ;
	active_anim = get_active_animation(goblin->animatable->animations);
	if (ft_strncmp(active_anim->name, run_prefix, sizeof(run_prefix) - 1) != 0)
	{
		animation_disable(active_anim);
		append_animation_suffix(goblin->look_direction, run_prefix, run_name);
		set_active_animation(&(goblin->animatable->animations), run_name);
	}
}

void	render_goblin_animation(t_context *gc, int map_x, int map_y)
{
	t_animatable	*animatable;
	t_animation		*animation;

	animatable = get_animatable(gc, vector2_new(map_x, map_y));
	animation = get_active_animation(animatable->animations);
	update_animation_image(animation);
}
