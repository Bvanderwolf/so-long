/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animation_query.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 15:33:48 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:59:48 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_utils.h"
#include "so_long_img.h"
#include "so_long_anim.h"
#include "ft_printf.h"

bool	is_disabled_animation(t_animation *anim)
{
	int	i;

	i = 0;
	while (anim->images[i] != NULL)
	{
		if (anim->images[i]->instances[anim->instance_index].enabled)
			return (false);
		i++;
	}
	return (true);
}

int	get_animation_frame(t_animation *anim)
{
	return ((((int)((mlx_get_time() - anim->start_time) / (ANIM_DELTA / anim->speed))) % anim->frame_count));
}

void	append_animation_suffix(t_vector2 dir, const char *prefix, char name[])
{
	ft_strcpy(name, prefix);
	if (vector2_equals_xy(dir, 1, 0))
		ft_strlcat(name, "_right.png", MAX_IMG_NAME_SIZE);
	else if (vector2_equals_xy(dir, -1, 0))
		ft_strlcat(name, "_left.png", MAX_IMG_NAME_SIZE);
}

int	get_animation_seq(t_context *gc, const char *name, mlx_image_t *seq[])
{
	int			i;
	size_t		name_len;
	char		img_name[MAX_IMG_NAME_SIZE + 2];
	mlx_image_t	*img;

	i = 0;
	sequence_name(name, img_name, i, &name_len);
	img = find_mlx_image(gc->images, img_name);
	seq[i] = img;
	while (img != NULL)
	{
		i++;
		img_name[name_len] = (i + '0');
		img = find_mlx_image(gc->images, img_name);
		if (img != NULL)
			seq[i] = img;
	}
	seq[i] = NULL;
	return (i);
}
