/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   text_query.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/18 16:18:17 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 16:20:45 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_img.h"
#include "so_long.h"
#include <stdlib.h>

t_text	*find_text(t_list *text, const char *name)
{
	t_list	*current;

	current = text;
	while (current != NULL)
	{
		if (ft_strcmp(name, ((t_text *)current->content)->name))
			return ((t_text *)current->content);
		current = current->next;
	}
	return (NULL);
}
