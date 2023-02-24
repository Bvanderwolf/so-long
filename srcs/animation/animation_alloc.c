/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animation_alloc.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 15:32:22 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 11:09:14 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_utils.h"
#include "so_long_img.h"
#include "so_long_anim.h"
#include "ft_printf.h"
#include "MLX42/MLX42.h"

static t_animation	*allocate_animation(const char *name, \
mlx_image_t *sequence[], int frames, float speed)
{
	t_animation	*animation;
	int			images_size;

	images_size = sizeof(mlx_image_t *) * (DEFAULT_ANIM_LEN + 1);
	animation = (t_animation *)ft_calloc(1, sizeof(t_animation));
	if (animation == NULL)
		return (NULL);
	animation->frame = 0;
	animation->frame_count = frames;
	animation->speed = speed;
	animation->start_time = mlx_get_time();
	ft_strcpy(animation->name, name);
	ft_memcpy(animation->images, sequence, images_size);
	return (animation);
}

t_animation	*create_animation(t_context *gc, const char *path, float speed)
{
	int			i;
	int			frames;
	mlx_image_t	*image;
	mlx_image_t	*sequence[DEFAULT_ANIM_LEN + 1];

	i = 0;
	frames = get_animation_seq(gc, path, sequence);
	while (sequence[i] != NULL)
	{
		image = sequence[i];
		i++;
	}
	return (allocate_animation(path, sequence, frames, speed));
}
