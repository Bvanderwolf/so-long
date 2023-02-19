/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector2_alloc.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 14:28:50 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/01/28 10:06:02 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_utils.h"
#include <stdlib.h>

void	vector2_arr_free(t_vector2 **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

t_vector2	*vector2_alloc(int x, int y)
{
	t_vector2	*v;

	v = (t_vector2 *)malloc(sizeof(t_vector2));
	if (v == NULL)
		return (NULL);
	v->x = x;
	v->y = y;
	return (v);
}

t_vector2	vector2_new(int x, int y)
{
	t_vector2	v;

	v.x = x;
	v.y = y;
	return (v);
}
