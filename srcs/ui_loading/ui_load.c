/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ui_load.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/14 14:50:31 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 13:18:50 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "so_long.h"
#include "so_long_img.h"

static bool	place_textual_info(t_context *gc)
{
	int	margin;

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
