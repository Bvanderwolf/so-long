/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_load_tiles.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 16:12:00 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:45:38 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "so_long.h"
#include "so_long_img.h"
#include "so_long_anim.h"
#include "so_long_utils.h"
#include "libft.h"
#include "ft_printf.h"
#include "MLX42/MLX42.h"

// Note to self: currently loads a single image from the map_tiles
// sprite sheet. goal is to replace this with the images from the
// door spritesheet so i can animate it.
static bool	img_load_exit(t_context *gc, mlx_texture_t *tex)
{
	t_image			*img;
	t_list			*img_item;

	img = load_img_xy(gc->mlx, tex, (uint32_t[]){TILE_SIZE, TILE_SIZE * 3}, TILE_SIZE);
	if (img == NULL)
	{
		ft_printf("Failed to load exit images from texture\n");
		return (unload_images(gc, &free_mlx_img), false);
	}
	ft_strcpy(img->name, IMG_EXIT);
	img_item = ft_lstnew(img);
	if (img_item == NULL)
		return (free(img), unload_images(gc, &free_mlx_img), false);
	ft_lstadd_front(&gc->images, img_item);
	return (true);
}

static bool	img_load_collectables(t_context *gc, mlx_texture_t *tex)
{
	if (!load_tile(gc, tex, 6, IMG_KEY))
		return (false);
	if (!load_tile(gc, tex, 1, IMG_GOLD))
		return (false);
	return (true);
}

bool	load_tile_images(t_context *gc)
{
	mlx_texture_t	*tex;
	const char		*path = "textures/map_tiles.png";

	tex = mlx_load_png(path);
	if (tex == NULL)
		return (ft_printf("Failed to load %s texture\n", path), false);
	if (!load_floor_images(gc, tex) || !load_wall_images(gc, tex) || !load_prop_images(gc, tex))
		return (mlx_delete_texture(tex), false);
	if (!img_load_exit(gc, tex) || !img_load_collectables(gc, tex))
		return (mlx_delete_texture(tex), false);
	mlx_delete_texture(tex);
	return (true);
}
