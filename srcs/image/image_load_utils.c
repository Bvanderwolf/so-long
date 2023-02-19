/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_load_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 10:30:45 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:43:42 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "so_long.h"
#include "so_long_img.h"
#include "so_long_anim.h"
#include "so_long_utils.h"
#include "ft_printf.h"
#include "libft.h"
#include "MLX42/MLX42.h"

// returns the pointer to the start of the name at the end of the path
// *Note: will include the .png extension at the end.
const char	*image_path_to_name(const char *path)
{
	return (path + (sizeof("textures")));
}

// Returns the texture coordinates to be used for the 
// mlx_texture_area_to_image function based on the number
// of the image, counting (from 1) from the top left to 
// bottom right.
t_vector2	number_coordinates(mlx_texture_t *tex, int num, int size)
{
	int	x;
	int	y;
	int	x_tiles;

	x_tiles = tex->width / size;
	if (num <= x_tiles)
		return (vector2_new((num - 1) * size, 0));
	y = 0;
	x = num - 1;
	while (x >= x_tiles)
	{
		x -= x_tiles;
		y++;
	}
	return (vector2_new(x * size, y * size));
}

t_image	*load_img_number(mlx_t *mlx, mlx_texture_t *tex, int num, int size)
{
	t_vector2	coordinates;
	uint32_t	xy[2];

	coordinates = number_coordinates(tex, num, size);
	xy[0] = coordinates.x;
	xy[1] = coordinates.y;
	return (load_img_xy(mlx, tex, xy, size));
}

t_image	*load_img_xy(mlx_t *mlx, mlx_texture_t *tex, uint32_t xy[2], int size)
{
	uint32_t		tile_width_height[2];
	mlx_image_t		*mlx_img;
	t_image			*img;

	tile_width_height[0] = size;
	tile_width_height[1] = size;
	mlx_img = mlx_texture_area_to_image(mlx, tex, xy, tile_width_height);
	if (mlx_img == NULL)
		return (ft_printf("Failed to create image from texture\n"), NULL);
	img = (t_image *)ft_calloc(1, sizeof(t_image));
	if (img == NULL)
	{
		ft_printf("Failed to create image wrapper");
		free(mlx_img);
		return (NULL);
	}
	img->value = mlx_img;
	return (img);
}

// Loads images from a linear sprite sheet into game context where "name"
// is the name of the sheet, "t" the texture of the sheet en "l" the amount
// of images.
bool	load_tile_sheet(t_context *gc, const char *name, mlx_texture_t *t, int l)
{
	char			img_name[MAX_IMG_NAME_SIZE];
	int				i;
	size_t			name_len;
	t_image			*img;
	t_list			*img_item;

	i = 0;
	sequence_name(name, img_name, i, &name_len);
	while (i < l)
	{
		img_name[name_len] = (i + '0');
		img = load_img_number(gc->mlx, t, (i + 1), TILE_SIZE);
		if (img == NULL)
			return (unload_images(gc, &free_mlx_img), false);
		ft_strcpy(img->name, img_name);
		img_item = ft_lstnew(img);
		if (img_item == NULL)
			return (free(img), unload_images(gc, &free_mlx_img), false);
		ft_lstadd_front(&(gc->images), img_item);
		i++;
	}
	return (true);
}
