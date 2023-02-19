/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_components.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 11:40:08 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/01/17 09:28:03 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdbool.h>

bool	is_not_wall_or_nl(int c)
{
	return (c != MAP_WALL && c != '\n');
}
