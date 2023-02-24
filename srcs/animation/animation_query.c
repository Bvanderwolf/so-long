/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animation_query.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 15:33:48 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 11:12:22 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_utils.h"
#include "so_long_img.h"
#include "so_long_anim.h"
#include "ft_printf.h"

bool	is_disabled_animation(t_animation *animation)
{
	int	i;

	i = 0;
	while (animation->images[i] != NULL)
	{
		if (animation->images[i]->instances[animation->instance_index].enabled)
			return (false);
		i++;
	}
	return (true);
}

int	get_animation_frame(t_animation *animation)
{
	const double	time = mlx_get_time() - animation->start_time;
	const float		delta = ANIM_DELTA / animation->speed;

	return ((((int)((time) / (delta))) % animation->frame_count));
}

void	append_animation_suffix(t_vector2 direction, const char *prefix, \
char name[])
{
	ft_strcpy(name, prefix);
	if (vector2_equals_xy(direction, 1, 0))
		ft_strlcat(name, "_right.png", MAX_IMG_NAME_SIZE);
	else if (vector2_equals_xy(direction, -1, 0))
		ft_strlcat(name, "_left.png", MAX_IMG_NAME_SIZE);
}

int	get_animation_seq(t_context *gc, const char *name, mlx_image_t *sequence[])
{
	int			i;
	size_t		name_len;
	char		img_name[MAX_IMG_NAME_SIZE + 2];
	mlx_image_t	*img;

	i = 0;
	sequence_name(name, img_name, i, &name_len);
	img = find_mlx_image(gc->images, img_name);
	sequence[i] = img;
	while (img != NULL)
	{
		i++;
		img_name[name_len] = (i + '0');
		img = find_mlx_image(gc->images, img_name);
		if (img != NULL)
			sequence[i] = img;
	}
	sequence[i] = NULL;
	return (i);
}
