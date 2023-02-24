/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   text_update.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/18 12:55:10 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 13:16:38 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "so_long_img.h"
#include "MLX42/MLX42.h"
#include "ft_printf.h"

// returns a disabled mlx instance for a character image
// will return -1 if none was found.
static int	get_disabled_instance(t_image *image)
{
	int	i;

	i = 0;
	while (i < image->value->count)
	{
		if (!image->value->instances[i].enabled)
			return (i);
		i++;
	}
	return (-1);
}

// pushes text image to screen, returning the instance index
static int	create_character_instance(t_context *gc, t_text *text, int i, \
t_image *image)
{
	return (mlx_image_to_window(gc->mlx,
			image->value,
			text->world_xy.x + (i * TEXT_SIZE),
			text->world_xy.y));
}

static bool	set_character_instance(t_context *gc, t_text *text, int i)
{
	t_image		*image;
	int			instance;
	char		name[2];
	int			world_x;
	int			world_y;

	str_set_char(name, text->value[i]);
	image = find_image(gc->images, name);
	world_x = text->world_xy.x + (i * (TEXT_SPACING));
	world_y = text->world_xy.y;
	instance = get_disabled_instance(image);
	if (instance == -1)
	{
		instance = create_character_instance(gc, text, i, image);
		if (instance == -1)
			return (false);
	}
	text->images[i] = image;
	text->images[i]->value->instances[instance].enabled = true;
	text->images[i]->value->instances[instance].x = world_x;
	text->images[i]->value->instances[instance].y = world_y;
	text->instances[i] = instance;
	return (true);
}

void	update_text_value(t_text *text, const char *value)
{
	ft_strcpy(text->value, value);
}

bool	update_window_with_text(t_context *gc, t_text *text)
{
	int		i;
	t_image	*image;

	i = 0;
	while (text->value[i] != '\0')
	{
		image = text->images[i];
		if (i < text->length)
		{
			if (image->name[0] != text->value[i])
			{
				image->value->instances[text->instances[i]].enabled = false;
				if (!set_character_instance(gc, text, i))
					return (false);
			}
		}
		else
		{
			if (!set_character_instance(gc, text, i))
				return (false);
			text->length++;
		}
		i++;
	}
	return (true);
}
