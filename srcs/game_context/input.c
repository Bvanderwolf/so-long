/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 11:58:10 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 11:58:37 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_utils.h"
#include "so_long_map.h"
#include <stdbool.h>
#include <stdio.h>

bool	is_key_pressed(t_keyinput key, mlx_key_data_t data)
{
	if (key == KEY_UP)
		return (data.key == MLX_KEY_W || data.key == MLX_KEY_UP);
	if (key == KEY_LEFT)
		return (data.key == MLX_KEY_A || data.key == MLX_KEY_LEFT);
	if (key == KEY_DOWN)
		return (data.key == MLX_KEY_S || data.key == MLX_KEY_DOWN);
	if (key == KEY_RIGHT)
		return (data.key == MLX_KEY_D || data.key == MLX_KEY_RIGHT);
	return (false);
}

t_vector2	get_walk_direction_from_input(mlx_key_data_t data)
{
	if (is_key_pressed(KEY_RIGHT, data) && data.action != MLX_PRESS)
		return (vector2_new(1, 0));
	if (is_key_pressed(KEY_LEFT, data) && data.action != MLX_PRESS)
		return (vector2_new(-1, 0));
	if (is_key_pressed(KEY_DOWN, data) && data.action != MLX_PRESS)
		return (vector2_new(0, 1));
	if (is_key_pressed(KEY_UP, data) && data.action != MLX_PRESS)
		return (vector2_new(0, -1));
	return (vector2_new(0, 0));
}
