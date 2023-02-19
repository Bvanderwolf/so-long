/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_alloc.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 11:40:25 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 14:35:38 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "so_long_utils.h"

void	str_set_char(char str[2], char c)
{
	str[0] = c;
	str[1] = '\0';
}

void	str_arr_free(char **arr)
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

// allocates memory for a duplicate string array of given string array "arr"
char	**str_arr_dup(char **arr)
{
	int		x;
	int		y;
	char	**dup_arr;

	dup_arr = (char **)malloc(sizeof(char *) * (str_arr_len(arr) + 1));
	if (dup_arr == NULL)
		return (NULL);
	y = 0;
	while (arr[y] != NULL)
	{
		x = 0;
		dup_arr[y] = (char *)malloc(sizeof(char) * (ft_strlen(arr[y]) + 1));
		while (arr[y][x] != '\0')
		{
			dup_arr[y][x] = arr[y][x];
			x++;
		}
		dup_arr[y][x] = '\0';
		y++;
	}
	dup_arr[y] = NULL;
	return (dup_arr);
}
