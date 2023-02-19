/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animation_list.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 15:19:42 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:53:41 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "so_long.h"
#include "so_long_utils.h"
#include "so_long_img.h"
#include "so_long_anim.h"
#include "so_long_anim.h"
#include "libft.h"
#include "MLX42/MLX42.h"

t_list	*create_animations(t_context *gc, const char *tex_names[], float speed)
{
	int		i;
	t_animation	*anim;
	t_list	*list_head;
	t_list	*list_new;

	i = 0;
	list_head = NULL;
	while (tex_names[i] != NULL)
	{
		anim = create_animation(gc, tex_names[i], speed);
		if (anim == NULL)
			return (ft_lstclear(&list_head, &free), NULL);
		list_new = ft_lstnew(anim);
		if (list_new == NULL)
			return (free(anim), ft_lstclear(&list_head, &free), NULL);
		ft_lstadd_back(&list_head, list_new);
		i++;
	}
	return (list_head);
}

// returns the head of the animations list as this is determined 
// to be the active one.
t_animation	*get_active_animation(t_list *animations)
{
	return ((t_animation *)(animations->content));
}

// sets the active animation, setting it as the new head of the
// animations list as this is determined to be the active one.
void	set_active_animation(t_list **animations, const char *name)
{
	t_list	*lst_item;
	t_list	*prev_lst_item;

	lst_item = *animations;
	prev_lst_item = NULL;
	while (lst_item != NULL)
	{
		if (ft_strcmp(((t_animation *)lst_item->content)->name, name))
			break ;
		prev_lst_item = lst_item;
		lst_item = lst_item->next;
	}
	if (prev_lst_item == NULL || lst_item == NULL)
		return ;
	prev_lst_item->next = lst_item->next;
	lst_item->next = *animations;
	*animations = lst_item;
	animation_enable((t_animation *)lst_item->content);
}
