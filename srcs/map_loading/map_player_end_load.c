/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_player_end_load.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/12 11:27:03 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:48:47 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "so_long.h"
#include "so_long_anim.h"
#include "ft_printf.h"

static void	render_player_end_effect(void *context)
{
	int				new_frame;
	t_effect *const	effect = context;
	t_animation			*animation;

	animation = get_active_animation(effect->animatable->animations);
	new_frame = get_animation_frame(animation);
	if (effect->frames_left != 0 && new_frame != animation->frame)
		effect->frames_left--;
	if (effect->frames_left == 0)
	{
		if (!is_disabled_animation(animation))
			animation_disable(animation);
		return ;
	}
	update_animation_image(animation);
}

bool	load_player_ending(t_context *gc)
{
	const char		*tex_names[] = { "player_end.png", NULL };
	t_effect		*effect;
	t_animatable	*animatable;
	t_list			*animatable_item;
	int32_t			xy[2];

	effect = (t_effect *)malloc(sizeof(t_effect));
	if (effect == NULL)
		return (NULL);
	animatable = create_animatable(gc, gc->player->map_xy, DEFAULT_ANIM_SPEED, tex_names);
	if (animatable == NULL)
		return (free(effect), false);
	animatable_item = ft_lstnew(animatable);
	if (animatable_item == NULL)
		return (free(effect), free(animatable), false);
	ft_lstadd_back(&(gc->animatables), animatable_item);
	effect->frames_left = get_active_animation(animatable->animations)->frame_count;
	effect->animatable = animatable;
	xy[0] = gc->player->world_xy.x;
	xy[1] = gc->player->world_xy.y;
	if (!animations_to_window(gc->mlx, animatable->animations, xy))
		return (false);
	if (!mlx_loop_hook(gc->mlx, &render_player_end_effect, effect))
		return (false);
	return (true);
}
