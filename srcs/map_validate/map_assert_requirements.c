/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_assert_requirements.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 12:02:09 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/09 12:11:43 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_map.h"
#include <stdbool.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

bool	assert_rectangular(char **map)
{
	int		i;
	size_t	first_line_len;

	first_line_len = ft_strtlen(map[0], '\n');
	i = 0;
	while (map[i] != NULL)
	{
		if (ft_strtlen(map[i], '\n') != first_line_len)
		{
			ft_printf(NO_RECT_MAP_MSG);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	assert_wall_boxing(char **map)
{
	if (strchr_pred(map[0], &is_not_wall_or_nl))
	{
		ft_printf(MISSING_WALL_MSG, "top");
		return (false);
	}
	if (str_arr_chr_pred(map, 0, &is_not_wall_or_nl))
	{
		ft_printf(MISSING_WALL_MSG, "left");
		return (false);
	}
	if (str_arr_chr_pred(map, ft_strtlen(map[0], '\n') - 1, &is_not_wall_or_nl))
	{
		ft_printf(MISSING_WALL_MSG, "right");
		return (false);
	}
	if (strchr_pred(map[str_arr_len(map) - 1], &is_not_wall_or_nl))
	{
		ft_printf(MISSING_WALL_MSG, "bottom");
		return (false);
	}
	return (true);
}

bool	assert_no_invalid_chars(char **map)
{
	int		x;
	int		y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] != '\n' && ft_strchr(VALID_MAP_CHARS, map[y][x]) == NULL)
				return (ft_printf(INVALID_MAP_CHAR, map[y][x]), false);
			x++;
		}
		y++;
	}
	return (true);
}
