/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ui_load.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/14 14:50:31 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:02:17 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "so_long.h"
#include "so_long_img.h"
#include "ft_printf.h"

static bool	place_number(t_context *gc, const char *name, int x, int y)
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

static bool	place_text(t_context *gc, const char *text, int margin)
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

static bool	place_textual_info(t_context *gc)
{
	int margin;

	margin = PANEL_MARGIN + PANEL_MARGIN + PANEL_MARGIN + PANEL_PADDING;
	if (!place_text(gc, COLLECTED_TEXT, margin))
		return (false);
	if (!place_text(gc, STEPS_TEXT, margin + TEXT_SIZE + PANEL_MARGIN))
		return (false);
	return (true);
}

static bool	place_panel_knob(t_context *gc)
{
	int			x;
	int			y;
	mlx_image_t	*img;
	
	x = (gc->mlx->width * 0.5) - (TILE_SIZE * 0.5);
	y = PANEL_MARGIN;
	img = find_mlx_image(gc->images, IMG_PANEL_KNOB);
	return (mlx_image_to_window(gc->mlx, img, x, y) != -1);
}

static mlx_image_t	*find_panel_image(t_context *gc, t_layout layout)
{
	if (layout.x == 0 && layout.y == 0)
		return (find_mlx_image(gc->images, IMG_PANEL_TOP_LEFT));
	if (layout.x == layout.width - 1 && layout.y == 0)
		return (find_mlx_image(gc->images, IMG_PANEL_TOP_RIGHT));
	if (layout.x == 0 && layout.y == layout.height - 1)
		return (find_mlx_image(gc->images, IMG_PANEL_BOTTOM_LEFT));
	if (layout.x == layout.width - 1 && layout.y == layout.height - 1)
		return (find_mlx_image(gc->images, IMG_PANEL_BOTTOM_RIGHT));
	if (layout.x == 0 && layout.y == 1)
		return (find_mlx_image(gc->images, IMG_PANEL_MIDDLE_LEFT));
	if (layout.x == layout.width - 1 && layout.y == 1)
		return (find_mlx_image(gc->images, IMG_PANEL_MIDDLE_RIGHT));
	if (layout.y == 0)
		return (find_mlx_image(gc->images, IMG_PANEL_TOP));
	if (layout.y == 1)
		return (find_mlx_image(gc->images, IMG_PANEL_MIDDLE));
	return (find_mlx_image(gc->images, IMG_PANEL_BOTTOM));
}

bool	place_panel_tiles(t_context *gc)
{
	mlx_image_t		*img;
	t_layout		layout;
	
	layout.width = (gc->mlx->width - TILE_SIZE) / TILE_SIZE;
	layout.height = 3;
	layout.y = 0;
	while (layout.y < layout.height)
	{
		layout.x = 0;
		while (layout.x < layout.width)
		{
			img = find_panel_image(gc, layout);
			if (mlx_image_to_window(
				gc->mlx,
				img, PANEL_MARGIN + (layout.x * TILE_SIZE),
				PANEL_MARGIN + (layout.y * TILE_SIZE)
				) == -1)
				return (false);
			layout.x++;
		}
		layout.y++;
	}
	return (true);
}

bool	load_user_interface(t_context *gc)
{
	if (!place_panel_tiles(gc))
		return (false);
	if (!place_textual_info(gc))
		return (false);
	if (!place_panel_knob(gc))
		return (false);
	return (true);
}
