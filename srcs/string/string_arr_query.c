/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_arr_query.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 11:35:31 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/01/05 11:36:23 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

char	*str_arr_chr_pred(char **strs, int x, bool (*predicate)(int))
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		if (predicate(strs[i][x]))
			return ((char *)(&strs[i][x]));
		i++;
	}
	return (NULL);
}

size_t	str_arr_len(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
		i++;
	return (i);
}

char	**str_arr_cpy(char **src, char **dst)
{
	int		x;
	int		y;

	y = 0;
	while (src[y] != NULL)
	{
		x = 0;
		while (src[y][x] != '\0')
		{
			dst[y][x] = src[y][x];
			x++;
		}
		y++;
	}
	return (dst);
}
