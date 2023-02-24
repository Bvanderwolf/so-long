/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ui_element_load.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 13:18:15 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 13:20:14 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "so_long.h"
#include "so_long_img.h"

bool	place_number(t_context *gc, const char *name, int x, int y)
{
	t_list	*text;
	t_text	*number;

	number = create_text(gc, name, "0");
	if (number == NULL)
		return (false);
	text = ft_lstnew(number);
	if (text == NULL)
		return (free(number), false);
	number->world_xy = vector2_new(x, y);
	ft_lstadd_back(&(gc->text), text);
	return (update_window_with_text(gc, number));
}

bool	place_text(t_context *gc, const char *text, int margin)
{
	const int	length = ft_strlen(text);
	mlx_image_t	*img;
	char		name[2];
	int			x;
	int			i;

	i = 0;
	name[1] = '\0';
	while (i < length)
	{
		name[0] = text[i];
		img = find_mlx_image(gc->images, name);
		x = TEXT_RIGHT_OFFSET + (i * (TEXT_SPACING));
		if (mlx_image_to_window(gc->mlx, img, x, margin) == -1)
			return (false);
		i++;
	}
	x = TEXT_RIGHT_OFFSET + (i * (TEXT_SPACING));
	return (place_number(gc, text, x, margin));
}
