/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animation.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/03 15:48:08 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 11:07:26 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_utils.h"
#include "so_long_img.h"
#include "so_long_anim.h"

bool	animations_to_window(mlx_t *mlx, t_list *animations, int32_t xy[2])
{
	t_list	*current;

	current = animations;
	while (current != NULL)
	{
		if (!animation_to_window(mlx, (t_animation *)current->content, xy))
			return (false);
		current = current->next;
	}
	return (true);
}

bool	animation_to_window(mlx_t *mlx, t_animation *animation, int32_t xy[2])
{
	int	i;
	int	instance_index;

	i = 0;
	while (animation->images[i] != NULL)
	{
		instance_index = mlx_image_to_window(mlx, animation->images[i], \
		xy[0], xy[1]);
		if (instance_index == -1)
			return (false);
		(&(animation->images[i]->instances[instance_index]))->enabled = false;
		i++;
	}
	animation->instance_index = instance_index;
	return (true);
}
