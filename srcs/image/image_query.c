/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_query.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 10:26:40 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:40:34 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "so_long_img.h"
#include "so_long_utils.h"
#include "ft_printf.h"
#include "libft.h"

void	sequence_name(const char *name, char *it_name, int start_i, size_t *len)
{
	*len = ft_strlen(name);
	ft_strcpy(it_name, name);
	it_name[*len] = (start_i + '0');
	it_name[*len + 1] = '\0';
}

t_image	*find_image(t_list *images, char *name)
{
	t_list	*current;

	current = images;
	while (current != NULL)
	{
		if (ft_strcmp(name, ((t_image *)current->content)->name))
			return ((t_image *)current->content);
		current = current->next;
	}
	return (NULL);
}

// Returns an mlx instance at given xy world coordinates
mlx_instance_t	*find_instance_xy(t_list *images, int x, int y)
{
	int				i;
	t_list			*current;
	t_image			*image;
	mlx_instance_t	instance;

	current = images;
	while (current != NULL)
	{
		i = 0;
		image = (t_image *)current->content;
		while (i < image->value->count)
		{
			instance = image->value->instances[i];
			if (instance.x == x && instance.y == y)
				return (&(image->value->instances[i]));
			i++;
		}
		current = current->next;
	}
	return (NULL);
}

mlx_image_t	*find_mlx_image(t_list *images, char *name)
{
	t_image	*image;

	image = find_image(images, name);
	if (image != NULL)
		return (image->value);
	return (NULL);
}
