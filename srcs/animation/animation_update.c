/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animation_update.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 15:35:42 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 11:15:02 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_utils.h"
#include "so_long_img.h"
#include "so_long_anim.h"
#include "ft_printf.h"

void	animation_enable(t_animation *animation)
{
	int			frame;
	mlx_image_t	*image;

	frame = get_animation_frame(animation);
	image = animation->images[frame];
	(&(image->instances[animation->instance_index]))->enabled = true;
}

void	animation_disable(t_animation *animation)
{
	int			i;
	mlx_image_t	*image;

	i = 0;
	while (i < animation->frame_count)
	{
		image = animation->images[i];
		(&(image->instances[animation->instance_index]))->enabled = false;
		i++;
	}
}

// Note To Self: now uses instances[0]. should work at some point
// with enemies which have multiple instances of their image in the game.
// Possible update: instead of having seq be an array of mlx_image_t let 
// it be an array of mlx_instance_t.
void	update_animation_position(t_animation *animation, \
t_vector2 new_position)
{
	int			i;
	mlx_image_t	*image;

	i = 0;
	while (animation->images[i] != NULL)
	{
		image = animation->images[i];
		(&(image->instances[animation->instance_index]))->x = new_position.x;
		(&(image->instances[animation->instance_index]))->y = new_position.y;
		i++;
	}
}

void	update_animation_image(t_animation *animation)
{
	int			new_frame;
	mlx_image_t	*image;
	mlx_image_t	*new_image;

	new_frame = get_animation_frame(animation);
	if (new_frame != animation->frame)
	{
		image = animation->images[animation->frame];
		new_image = animation->images[new_frame];
		(&(image->instances[animation->instance_index]))->enabled = false;
		(&(new_image->instances[animation->instance_index]))->enabled = true;
		animation->frame = new_frame;
	}
}
