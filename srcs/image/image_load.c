/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_load.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 13:36:08 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:45:52 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_img.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdbool.h>
#include <stdlib.h>

bool	load_sheets_at_paths(t_context *gc, const char *paths[], int sheet_length)
{
	int				i;
	mlx_texture_t	*tex;
	const char		*tex_name;

	i = 0;
	while (paths[i] != NULL)
	{
		tex = mlx_load_png(paths[i]);
		if (tex == NULL)
			return (ft_printf("Failed to load %s texture\n", paths[i]), false);
		tex_name = image_path_to_name(paths[i]);
		if (!load_tile_sheet(gc, tex_name, tex, sheet_length))
		{
			ft_printf("Failed to load %s images from texture\n", paths[i]);
			return (false);
		}
		mlx_delete_texture(tex);
		i++;
	}
	return (true);
}

/// @brief loads tile image number "n" into context from texture "tex"
/// with name "name".
/// @param gc the game context.
/// @param tex the texture to load the image from.
/// @param n the number of the image in the sprite sheet.
/// @param name the name of the image.
/// @return 
bool	load_tile(t_context *gc, mlx_texture_t *tex, int n, char *name)
{
	t_image			*img;
	t_list			*img_item;

	img = load_img_number(gc->mlx, tex, n, TILE_SIZE);
	if (img == NULL)
	{
		ft_printf("Failed to load %s tile images from texture\n", name);
		return (unload_images(gc, &free_mlx_img), false);
	}
	ft_strcpy(img->name, name);
	img_item = ft_lstnew(img);
	if (img_item == NULL)
		return (free(img), unload_images(gc, &free_mlx_img), false);
	ft_lstadd_front(&gc->images, img_item);
	return (true);
}

/// @brief loads text image number "n" into context from texture "tex"
/// with name "name".
/// @param gc the game context.
/// @param tex the texture to load the image from.
/// @param n the number of the image in the sprite sheet.
/// @param name the name of the image.
/// @return 
bool	load_text(t_context *gc, mlx_texture_t *tex, int n, char *name)
{
	t_image			*img;
	t_list			*img_item;

	img = load_img_number(gc->mlx, tex, n, TEXT_SIZE);
	if (img == NULL)
	{
		ft_printf("Failed to load %s images from texture\n", name);
		return (unload_images(gc, &free_mlx_img), false);
	}
	ft_strcpy(img->name, name);
	img_item = ft_lstnew(img);
	if (img_item == NULL)
		return (free(img), unload_images(gc, &free_mlx_img), false);
	ft_lstadd_front(&gc->images, img_item);
	return (true);
}

bool	load_images(t_context *gc)
{
	gc->images = NULL;
	if (!load_player_image(gc))
		return (false);
	if (!load_tile_images(gc))
		return (false);
	if (!load_enemy_images(gc))
		return (false);
	if (!load_ui_images(gc))
		return (false);
	return (true);
}
