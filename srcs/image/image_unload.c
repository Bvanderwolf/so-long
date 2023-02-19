/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_unload.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 10:33:34 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/01/27 14:42:50 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"
#include "so_long_img.h"
#include "MLX42/MLX42.h"

void	unload_images(t_context *gc, t_img_unload unload)
{
	t_list	*current;

	current = gc->images;
	while (current != NULL)
	{
		unload(gc->mlx, ((t_image *)current->content)->value);
		current = current->next;
	}
	ft_lstclear(&(gc->images), &free);
}

void	free_mlx_img(mlx_t *mlx, mlx_image_t *img)
{
	(void)mlx;
	free(img);
}
