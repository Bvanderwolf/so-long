/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector2_query.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 11:40:58 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/01/27 12:33:02 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_utils.h"
#include <stdlib.h>
#include <stdbool.h>

bool	vector2_equals(t_vector2 lhs, t_vector2 rhs)
{
	return (lhs.x == rhs.x && lhs.y == rhs.y);
}

bool	vector2_equals_xy(t_vector2 v, int x, int y)
{
	return (v.x == x && v.y == y);
}

t_vector2	vector2_add_xy(t_vector2 v, int x, int y)
{
	v.x += x;
	v.y += y;
	return (v);
}

t_vector2	vector2_add(t_vector2 lhs, t_vector2 rhs)
{
	lhs.x += rhs.x;
	lhs.y += rhs.y;
	return (lhs);
}

int	vector2_sqr_distance(t_vector2 v1, t_vector2 v2)
{
	return (((v2.y - v1.y) * (v2.y - v1.y)) + ((v2.x - v1.x) * (v2.x - v1.x)));
}
