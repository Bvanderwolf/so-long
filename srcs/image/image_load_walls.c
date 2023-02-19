/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_load_walls.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 16:48:13 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:45:09 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "so_long.h"
#include "so_long_img.h"
#include "MLX42/MLX42.h"

// Note to self: add t_load_info { int: number, char *name }
// and create a stack allocated array to loop through.
bool	load_wall_images(t_context *gc, mlx_texture_t *tex)
{
	if (!load_tile(gc, tex, 44, IMG_WALL))
		return (false);
	if (!load_tile(gc, tex, 49, IMG_ROOF_LEFT))
		return (false);
	if (!load_tile(gc, tex, 50, IMG_ROOF_RIGHT))
		return (false);
	if (!load_tile(gc, tex, 41, IMG_ROOF_CORNER_TOP_LEFT))
		return (false);
	if (!load_tile(gc, tex, 40, IMG_ROOF_CORNER_TOP_RIGHT))
		return (false);
	if (!load_tile(gc, tex, 59, IMG_ROOF_CORNER_BOTTOM_LEFT))
		return (false);
	if (!load_tile(gc, tex, 58, IMG_ROOF_CORNER_BOTTOM_RIGHT))
		return (false);
	if (!load_tile(gc, tex, 57, IMG_ROOF_BOTTOM))
		return (false);
	if (!load_tile(gc, tex, 66, IMG_ROOF_TOP))
		return (false);
	return (true);
}
