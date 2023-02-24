/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 10:39:12 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 13:20:42 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	lst_free(t_list **lst)
{
	t_list	*next;

	while (*lst != NULL)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
}

void	lst_mergeback(t_list **lst, t_list *range)
{
	t_list	*current;

	current = range;
	while (current != NULL)
	{
		ft_lstadd_back(lst, current);
		current = current->next;
	}
}
