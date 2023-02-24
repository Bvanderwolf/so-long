/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_load_walls.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 16:48:13 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 12:48:20 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "so_long.h"
#include "so_long_img.h"
#include "MLX42/MLX42.h"

bool	load_wall_images(t_context *gc, mlx_texture_t *texture)
{
	return (load_tile(gc, texture, 44, IMG_WALL)
		&& load_tile(gc, texture, 49, IMG_ROOF_LEFT)
		&& load_tile(gc, texture, 50, IMG_ROOF_RIGHT)
		&& load_tile(gc, texture, 41, IMG_ROOF_CORNER_TOP_LEFT)
		&& load_tile(gc, texture, 40, IMG_ROOF_CORNER_TOP_RIGHT)
		&& load_tile(gc, texture, 59, IMG_ROOF_CORNER_BOTTOM_LEFT)
		&& load_tile(gc, texture, 58, IMG_ROOF_CORNER_BOTTOM_RIGHT)
		&& load_tile(gc, texture, 57, IMG_ROOF_BOTTOM)
		&& load_tile(gc, texture, 66, IMG_ROOF_TOP));
}
