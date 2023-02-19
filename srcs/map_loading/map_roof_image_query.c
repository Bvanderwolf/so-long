/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_roof_image_query.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 15:10:49 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/01/26 12:08:18 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_img.h"
#include "so_long_utils.h"
#include "so_long_map.h"
#include <stdlib.h>
#include <stdio.h>

mlx_image_t	*get_roof_top_corner_image(t_context *gc, int x, int y)
{
	if (is_roof_corner_top_left(gc->map, x, y))
		return (find_mlx_image(gc->images, IMG_ROOF_CORNER_TOP_LEFT));
	if (is_roof_corner_top_right(gc->map, x, y))
		return (find_mlx_image(gc->images, IMG_ROOF_CORNER_TOP_RIGHT));
	return (NULL);
}

mlx_image_t	*get_roof_image(t_context *gc, int x, int y)
{
	if (is_roof_corner_bottom_left(gc->map, x, y))
		return (find_mlx_image(gc->images, IMG_ROOF_CORNER_BOTTOM_LEFT));
	if (is_roof_corner_bottom_right(gc->map, x, y))
		return (find_mlx_image(gc->images, IMG_ROOF_CORNER_BOTTOM_RIGHT));
	if (is_roof_bottom(gc->map, x, y))
		return (find_mlx_image(gc->images, IMG_ROOF_BOTTOM));
	if (is_roof_top(gc->map, x, y))
		return (find_mlx_image(gc->images, IMG_ROOF_TOP));
	if (is_roof_left(gc->map, x, y))
		return (find_mlx_image(gc->images, IMG_ROOF_LEFT));
	if (is_roof_right(gc->map, x, y))
		return (find_mlx_image(gc->images, IMG_ROOF_RIGHT));
	return (get_roof_top_corner_image(gc, x, y));
}
