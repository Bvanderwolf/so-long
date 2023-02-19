/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_prop_load.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 18:33:47 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:48:25 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_map.h"

bool	load_props(t_context *gc)
{
	if (!load_wall_props(gc))
		return (false);
	if (!load_non_wall_props(gc))
		return (false);
	return (true);
}
