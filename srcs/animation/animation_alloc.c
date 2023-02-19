/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animation_alloc.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 15:32:22 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:30:55 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_utils.h"
#include "so_long_img.h"
#include "so_long_anim.h"
#include "ft_printf.h"
#include "MLX42/MLX42.h"

static t_animation	*anim_new(const char *name, mlx_image_t *seq[], int frames, float speed)
{
	t_animation	*anim;

	anim = (t_animation *)ft_calloc(1, sizeof(t_animation));
	if (anim == NULL)
		return (NULL);
	anim->frame = 0;
	anim->frame_count = frames;
	anim->speed = speed;
	anim->start_time = mlx_get_time();
	ft_strcpy(anim->name, name);
	ft_memcpy(anim->images, seq, sizeof(mlx_image_t *) * (DEFAULT_ANIM_LEN + 1));
	return (anim);
}

t_animation	*create_animation(t_context *gc, const char *tex_name, float speed)
{
	int			i;
	int			frames;
	mlx_image_t	*img;
	mlx_image_t	*seq[DEFAULT_ANIM_LEN + 1];

	i = 0;
	frames = get_animation_seq(gc, tex_name, seq);
	while (seq[i] != NULL)
	{
		img = seq[i];
		i++;
	}
	return (anim_new(tex_name, seq, frames, speed));
}
