/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   context_management.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 10:55:07 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:48:47 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "so_long.h"
#include "so_long_map.h"
#include "so_long_img.h"
#include "so_long_utils.h"
#include "MLX42/MLX42.h"
#include "ft_printf.h"
#include "so_long_anim.h"
#include <stdlib.h>

void	end_game(const char *message, t_context *gc)
{
	t_animation	*active_animation;
	
	if (!load_player_ending(gc))
		exit_clearing_context(gc);
	active_animation = get_active_animation(gc->player->animations);
	animation_disable(active_animation);
	ft_printf(message, gc->player->steps);
	gc->completed = true;
}

void	check_game_completion(t_context *gc)
{
	t_vector2	player_position;

	if (gc->collectables != gc->player->collectables)
		return ;
	player_position = gc->player->map_xy;
	if (is_map_tile(gc->map, player_position, MAP_EXIT))
		end_game("completed the game after %d steps.\npress ESC to exit\n", gc);
}

void	exit_clearing_context(t_context *gc)
{
	if (gc->player != NULL)
		unload_player(gc);
	if (gc->images != NULL)
		unload_images(gc, &mlx_delete_image);
	if (gc->map != NULL)
		unload_map(gc);
	if (gc->collision_hooks != NULL)
		lst_free(&(gc->collision_hooks));
	if (gc->position_hooks != NULL)
		lst_free(&(gc->position_hooks));
	if (gc->animatables != NULL)
		ft_lstclear(&(gc->animatables), &free_animatable);
	if (gc->enemies != NULL)
		ft_lstclear(&(gc->enemies), &free_enemy);
	if (gc->text != NULL)
		ft_lstclear(&(gc->text), &free);
	if (gc->mlx != NULL)
		mlx_terminate(gc->mlx);
	free(gc);
	exit(EXIT_FAILURE);
}

void	game_terminate(t_context *gc)
{
	unload_player(gc);
	unload_images(gc, &mlx_delete_image);
	unload_map(gc);
	lst_free(&(gc->collision_hooks));
	lst_free(&(gc->position_hooks));
	ft_lstclear(&(gc->animatables), &free_animatable);
	ft_lstclear(&(gc->enemies), &free_enemy);
	ft_lstclear(&(gc->text), &free);
	mlx_terminate(gc->mlx);
	free(gc);
}

bool	game_init(t_context *gc)
{
	if (!load_images(gc))
		return (false);
	if (!load_map_tiles(gc))
		return (false);
	if (!load_user_interface(gc))
		return (false);
	return (true);
}
