/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_load_ui.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 16:18:49 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 15:07:12 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "so_long.h"
#include "so_long_img.h"
#include "ft_printf.h"
#include "MLX42/MLX42.h"

static bool	load_panel_images(t_context *gc)
{
	const char		*path = "textures/ui_panel_tiles.png";
	char *const		names[] = {
		IMG_PANEL_TOP_LEFT, IMG_PANEL_TOP, IMG_PANEL_TOP_RIGHT,
		IMG_PANEL_MIDDLE_LEFT, IMG_PANEL_MIDDLE, IMG_PANEL_MIDDLE_RIGHT,
		IMG_PANEL_BOTTOM_LEFT, IMG_PANEL_BOTTOM, IMG_PANEL_BOTTOM_RIGHT,
		NULL,
	};
	mlx_texture_t	*texture;
	int				i;

	texture = mlx_load_png(path);
	if (texture == NULL)
		return (false);
	i = 0;
	while (names[i] != NULL)
	{
		if (!load_tile(gc, texture, i + 1, names[i]))
			return (false);
		i++;
	}
	mlx_delete_texture(texture);
	return (true);
}

static bool	load_panel_knob_images(t_context *gc)
{
	const char		*path = "textures/ui_panel_knob.png";
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (texture == NULL)
		return (false);
	if (!load_tile(gc, texture, 1, IMG_PANEL_KNOB))
		return (false);
	mlx_delete_texture(texture);
	return (true);
}

static bool	load_text_images(t_context *gc)
{
	const char		*path = "textures/alphabet.png";
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (texture == NULL)
		return (false);
	if (!load_alphabet_images(gc, texture))
		return (false);
	if (!load_numbers_and_equals_images(gc, texture))
		return (false);
	mlx_delete_texture(texture);
	return (true);
}

bool	load_ui_images(t_context *gc)
{
	if (!load_text_images(gc))
		return (false);
	if (!load_panel_images(gc))
		return (false);
	if (!load_panel_knob_images(gc))
		return (false);
	return (true);
}
