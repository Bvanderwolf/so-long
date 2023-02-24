/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_load_text.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 12:54:51 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 12:56:44 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "so_long.h"
#include "so_long_img.h"
#include "ft_printf.h"
#include "MLX42/MLX42.h"

bool	load_numbers_and_equals_images(t_context *gc, mlx_texture_t *texture)
{
	char			name[2];
	const int		max = NUMBER_AND_EQUAL_CHAR_COUNT;
	int				i;

	i = 0;
	name[1] = '\0';
	while (i <= max)
	{
		name[0] = (i + '0');
		if (!load_text(gc, texture, (i + 49), name))
			return (false);
		i++;
	}
	return (true);
}

bool	load_alphabet_images(t_context *gc, mlx_texture_t *texture)
{
	char			name[2];
	const int		max = ALPHA_CHAR_COUNT;
	int				i;

	i = 0;
	name[1] = '\0';
	while (i < max)
	{
		name[0] = (i + 'a');
		if (!load_text(gc, texture, i + 98, name))
			return (false);
		i++;
	}
	return (true);
}
