/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rand_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 11:50:45 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 13:20:58 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

float	rand01(void)
{
	return (rand() / (float)RAND_MAX);
}

float	rand_minmax(float min, float max)
{
	const float	range = max - min;
	const float	rand = rand01();

	return (min + (rand * range));
}
