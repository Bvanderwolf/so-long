/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_load_props.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/28 10:27:09 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:45:38 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "so_long.h"
#include "so_long_img.h"
#include "MLX42/MLX42.h"
#include "ft_printf.h"

static bool	img_load_torch(t_context *gc)
{
	mlx_texture_t	*tex;
	const char		*tex_name;
	const char		*path = "textures/torch_light.png";

	tex = mlx_load_png(path);
	if (tex == NULL)
		return (ft_printf("Failed to load %s texture\n", path), false);
	tex_name = image_path_to_name(path);
	if (!load_tile_sheet(gc, tex_name, tex, DEFAULT_ANIM_LEN))
	{
		ft_printf("Failed to load %s images from texture\n", path);
		return (false);
	}
	mlx_delete_texture(tex);
	return (true);
}

bool	load_prop_images(t_context *gc, mlx_texture_t *tex)
{
	if (!load_tile(gc, tex, 2, IMG_KEG_WALL))
		return (false);
	if (!load_tile(gc, tex, 3, IMG_CLOSET_WALL))
		return (false);
	if (!load_tile(gc, tex, 15, IMG_SHORT_TABLE_WALL))
		return (false);
	if (!load_tile(gc, tex, 10, IMG_LONG_TABLE_WALL_LEFT))
		return (false);
	if (!load_tile(gc, tex, 11, IMG_LONG_TABLE_WALL_RIGHT))
		return (false);
	if (!load_tile(gc, tex, 4, IMG_BANNER_GREEN))
		return (false);
	if (!load_tile(gc, tex, 5, IMG_BANNER_RED))
		return (false);
	if (!load_tile(gc, tex, 14, IMG_BANNER_SKELETON))
		return (false);
	if (!img_load_torch(gc))
		return (false);
	return (true);
}