/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animation.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/03 15:48:08 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:29:22 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_utils.h"
#include "so_long_img.h"
#include "so_long_anim.h"

bool	animations_to_window(mlx_t *mlx, t_list *anims, int32_t xy[2])
{
	t_list	*current;

	current = anims;
	while (current != NULL)
	{
		if (!animation_to_window(mlx, (t_animation *)current->content, xy))
			return (false);
		current = current->next;
	}
	return (true);
}

bool	animation_to_window(mlx_t *mlx, t_animation *anim, int32_t xy[2])
{
	int	i;
	int	instance_index;

	i = 0;
	while (anim->images[i] != NULL)
	{
		instance_index = mlx_image_to_window(mlx, anim->images[i], xy[0], xy[1]);
		if (instance_index == -1)
			return (false);
		(&(anim->images[i]->instances[instance_index]))->enabled = false;
		i++;
	}
	anim->instance_index = instance_index;
	return (true);
}
