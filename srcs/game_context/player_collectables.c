/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_collectables.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/21 16:50:35 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/12 10:55:04 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_img.h"
#include "so_long_map.h"

static int	get_collectable_neighbours(t_context *c, mlx_instance_t **buffer)
{
	int				i;
	int				count;
	t_vector2		map_pos;
	mlx_instance_t	*instance;
	const t_vector2	positions[] = {
		map_to_world_position_xy(c->player->map_xy.x, c->player->map_xy.y - 1),
		map_to_world_position_xy(c->player->map_xy.x - 1, c->player->map_xy.y),
		map_to_world_position_xy(c->player->map_xy.x, c->player->map_xy.y + 1),
		map_to_world_position_xy(c->player->map_xy.x + 1, c->player->map_xy.y)
	};

	i = 0;
	count = 0;
	while (i < NEIGHBOUR_COUNT)
	{
		instance = find_instance_xy(c->images, positions[i].x, positions[i].y);
		map_pos = world_to_map_position(positions[i]);
		if (instance != NULL && is_map_tile(c->map, map_pos, MAP_COLLECTABLE))
		{
			buffer[count] = instance;
			count++;
		}
		i++;
	}
	return (count);
}

void	update_player_collectables(t_context *gc)
{
	const int		min_distance_sqrd = TILE_SIZE * TILE_SIZE / 3;
	mlx_instance_t	*collider;
	mlx_instance_t	*buffer[NEIGHBOUR_COUNT];
	int				count;

	count = get_collectable_neighbours(gc, buffer);
	collider = get_collider(gc->player, buffer, count, min_distance_sqrd);
	if (collider == NULL || !collider->enabled)
		return ;
	gc->player->collectables++;
	collider->enabled = false;
	invoke_player_collision(COLLECTABLE_COLLISION, gc);
}
