/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_load_floor.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 14:59:40 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 12:46:54 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_img.h"
#include "ft_printf.h"
#include "libft.h"

bool	load_floor_images(t_context *gc, mlx_texture_t *texture)
{
	return (load_tile(gc, texture, 12, IMG_FLOOR)
		&& load_tile(gc, texture, 13, IMG_FLOOR_ONE)
		&& load_tile(gc, texture, 16, IMG_FLOOR_TOP_LEFT)
		&& load_tile(gc, texture, 17, IMG_FLOOR_TOP)
		&& load_tile(gc, texture, 18, IMG_FLOOR_TOP_RIGHT)
		&& load_tile(gc, texture, 21, IMG_FLOOR_TWO)
		&& load_tile(gc, texture, 22, IMG_FLOOR_THREE)
		&& load_tile(gc, texture, 23, IMG_FLOOR_FOUR)
		&& load_tile(gc, texture, 25, IMG_FLOOR_LEFT)
		&& load_tile(gc, texture, 27, IMG_FLOOR_RIGHT)
		&& load_tile(gc, texture, 30, IMG_FLOOR_FIVE)
		&& load_tile(gc, texture, 31, IMG_FLOOR_SIX)
		&& load_tile(gc, texture, 32, IMG_FLOOR_SEVEN));
}
