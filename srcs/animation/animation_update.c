/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animation_update.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 15:35:42 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:30:30 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_utils.h"
#include "so_long_img.h"
#include "so_long_anim.h"
#include "ft_printf.h"

void	animation_enable(t_animation *animation)
{
	int	frame;

	frame = get_animation_frame(animation);
	(&(animation->images[frame]->instances[animation->instance_index]))->enabled = true;
}

void	animation_disable(t_animation *animation)
{
	int	i;

	i = 0;
	while (i < animation->frame_count)
	{
		(&(animation->images[i]->instances[animation->instance_index]))->enabled = false;
		i++;
	}
}

// Note To Self: now uses instances[0]. should work at some point
// with enemies which have multiple instances of their image in the game.
// Possible update: instead of having seq be an array of mlx_image_t let 
// it be an array of mlx_instance_t.
void	update_animation_position(t_animation *anim, t_vector2 new_position)
{
	int	i;

	i = 0;
	while (anim->images[i] != NULL)
	{
		(&(anim->images[i]->instances[anim->instance_index]))->x = new_position.x;
		(&(anim->images[i]->instances[anim->instance_index]))->y = new_position.y;
		i++;
	}
}

void	update_animation_image(t_animation *anim)
{
	int	new_frame;

	new_frame = get_animation_frame(anim);
	if (new_frame != anim->frame)
	{
		(&(anim->images[anim->frame]->instances[anim->instance_index]))->enabled = false;
		(&(anim->images[new_frame]->instances[anim->instance_index]))->enabled = true;
		anim->frame = new_frame;
	}
}
