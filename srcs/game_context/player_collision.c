/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_collision.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 08:47:29 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 12:02:58 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "ft_printf.h"
#include "so_long_map.h"
#include <stdio.h>

/// @brief returns an image instance from given amount of
/// instances from buffer that collides with player
/// based on a squared distance
/// Note: make sure distance is the squared distance that you want to
// test as the distance is calculated without using square root.
/// @param player the player instance.
/// @param instance_buffer the buffer of image instances.
/// @param instance_count the amount of image instances.
/// @param squared_distance the squared distance to test against.
/// @return 
mlx_instance_t	*get_collider(t_player *player, \
mlx_instance_t **instance_buffer, int instance_count, int squared_distance)
{
	t_vector2	position;
	int			i;

	i = 0;
	while (i < instance_count)
	{
		position = vector2_new(instance_buffer[i]->x, instance_buffer[i]->y);
		if (vector2_sqr_distance(player->world_xy, position) < squared_distance)
			return (instance_buffer[i]);
		i++;
	}
	return (NULL);
}

void	update_player_collectables_ui(t_context *gc)
{
	char	*number;
	t_text	*text;

	number = ft_itoa(gc->player->collectables);
	if (number == NULL)
		exit_clearing_context(gc);
	text = find_text(gc->text, COLLECTED_TEXT);
	update_text_value(text, number);
	update_window_with_text(gc, text);
	ft_printf("collected %s from the available %d collectables\n", \
	number, gc->collectables);
	free(number);
}

void	handle_player_collision(t_collision collision, t_context *gc)
{
	if (collision == COLLECTABLE_COLLISION)
		update_player_collectables_ui(gc);
	else if (collision == ENEMY_COLLISION)
		end_game("lost the game after %d steps.\npress ESC to exit\n", gc);
}

void	invoke_player_collision(t_collision collider, t_context *gc)
{
	t_list	*current;

	current = gc->collision_hooks;
	while (current != NULL)
	{
		((t_collision_hook)current->content)(collider, gc);
		current = current->next;
	}
}

// adds a hook to the player collision event, returning 
// the collider and the game context
bool	player_collision_hook(t_context *gc, t_collision_hook hook)
{
	t_list	*hook_item;

	hook_item = ft_lstnew(hook);
	if (hook_item == NULL)
		return (perror("failed adding player collision hook"), false);
	ft_lstadd_back(&(gc->collision_hooks), hook_item);
	return (true);
}
