/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_load_floor.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 14:59:40 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:45:32 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_img.h"
#include "ft_printf.h"
#include "libft.h"

// Note to self: currently loads a single floor image. goal is to load
// multiple to diversify.
bool	load_floor_images(t_context *gc, mlx_texture_t *tex)
{
	if (!load_tile(gc, tex, 12, IMG_FLOOR))
		return (false);
	if (!load_tile(gc, tex, 13, IMG_FLOOR_ONE))
		return (false);
	if (!load_tile(gc, tex, 16, IMG_FLOOR_TOP_LEFT))
		return (false);
	if (!load_tile(gc, tex, 17, IMG_FLOOR_TOP))
		return (false);
	if (!load_tile(gc, tex, 18, IMG_FLOOR_TOP_RIGHT))
		return (false);
	if (!load_tile(gc, tex, 21, IMG_FLOOR_TWO))
		return (false);
	if (!load_tile(gc, tex, 22, IMG_FLOOR_THREE))
		return (false);
	if (!load_tile(gc, tex, 23, IMG_FLOOR_FOUR))
		return (false);
	if (!load_tile(gc, tex, 25, IMG_FLOOR_LEFT))
		return (false);
	if (!load_tile(gc, tex, 27, IMG_FLOOR_RIGHT))
		return (false);
	if (!load_tile(gc, tex, 30, IMG_FLOOR_FIVE))
		return (false);
	if (!load_tile(gc, tex, 31, IMG_FLOOR_SIX))
		return (false);
	if (!load_tile(gc, tex, 32, IMG_FLOOR_SEVEN))
		return (false);
	return (true);
}
