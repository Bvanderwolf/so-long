/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_load_ui.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 16:18:49 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:45:52 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "so_long.h"
#include "so_long_img.h"
#include "ft_printf.h"
#include "MLX42/MLX42.h"

static bool	img_load_panel(t_context *gc)
{
	const char		*path = "textures/ui_panel_tiles.png";
	char *const		names[] = {
		IMG_PANEL_TOP_LEFT, IMG_PANEL_TOP, IMG_PANEL_TOP_RIGHT,
		IMG_PANEL_MIDDLE_LEFT, IMG_PANEL_MIDDLE, IMG_PANEL_MIDDLE_RIGHT,
		IMG_PANEL_BOTTOM_LEFT, IMG_PANEL_BOTTOM, IMG_PANEL_BOTTOM_RIGHT,
		NULL,
	};
	mlx_texture_t	*tex;
	int				i;
	
	tex = mlx_load_png(path);
	if (tex == NULL)
		return (false);
	i = 0;
	while (names[i] != NULL)
	{
		if (!load_tile(gc, tex, i + 1, names[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	img_load_panel_knob(t_context *gc)
{
	const char		*path = "textures/ui_panel_knob.png";
	mlx_texture_t	*tex;
	
	tex = mlx_load_png(path);
	if (tex == NULL)
		return (false);
	return (load_tile(gc, tex, 1, IMG_PANEL_KNOB));
}

static bool	img_load_numbers_and_equals(t_context *gc, mlx_texture_t *tex)
{
	char			name[2];
	const int		max = NUMBER_AND_EQUAL_CHAR_COUNT;
	int				i;

	i = 0;
	name[1] = '\0';
	while (i <= max)
	{
		name[0] = (i + '0');
		if (!load_text(gc, tex, (i + 49), name))
			return (false);
		i++;
	}
	return (true);
}

static bool	img_load_alphabet(t_context *gc, mlx_texture_t *tex)
{
	char			name[2];
	const int		max = ALPHA_CHAR_COUNT;
	int				i;

	i = 0;
	name[1] = '\0';
	while (i < max)
	{
		name[0] = (i + 'a');
		if (!load_text(gc, tex, i + 98, name))
			return (false);
		i++;
	}
	return (true);
}

static bool	img_load_text(t_context *gc)
{
	const char		*path = "textures/alphabet.png";
	mlx_texture_t	*tex;
	
	tex = mlx_load_png(path);
	if (tex == NULL)
		return (false);
	if (!img_load_alphabet(gc, tex))
		return (false);
	if (!img_load_numbers_and_equals(gc, tex))
		return (false);
	return (true);
}

bool	load_ui_images(t_context *gc)
{
	if (!img_load_text(gc))
		return (false);
	if (!img_load_panel(gc))
		return (false);
	if (!img_load_panel_knob(gc))
		return (false);
	return (true);
}