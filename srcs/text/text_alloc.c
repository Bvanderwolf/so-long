/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   text_alloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/18 12:05:52 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 16:20:52 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "so_long_img.h"
#include "so_long_utils.h"
#include "libft.h"

static void	cpy_text_char_images(t_context *gc, t_image **images)
{
	const char	chars[] = "abcdefghijklmnopqrstuvwxyz0123456789:";
	char		name[2];
	int			i;

	i = 0;
	name[1] = '\0';
	while (chars[i] != '\0')
	{
		name[0] = chars[i];
		images[i] = find_image(gc->images, name);
		i++;
	}
	images[i] = NULL;
}

// allocates a new text structure holding given char value.
// Note that the length has not been set yet as no update
// to the screen is done. After creation, an update to the
// screen should be done to make length and instances compatible.
t_text	*create_text(t_context *gc, const char *name, const char *value)
{
	t_text	*text;

	text = (t_text *)ft_calloc(1, sizeof(t_text));
	if (text == NULL)
		return (NULL);
	ft_strcpy(text->name, name);
	ft_strcpy(text->value, value);
	cpy_text_char_images(gc, text->images);
	return (text);
}
