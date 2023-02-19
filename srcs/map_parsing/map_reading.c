/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_reading.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 11:07:27 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/09 12:15:14 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "so_long_utils.h"

static int	alloc_map_lines(int fd, char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
		{
			perror("Failed reading map file while loading lines");
			return (str_arr_free(map), 0);
		}
		i++;
	}
	map[i] = NULL;
	return (1);
}

bool	check_file_extension(const char *fn)
{
	const char	extension[] = ".ber";
	int			i;

	i = 0;
	while (fn[i] != '\0' && fn[i] != '.')
		i++;
	if (fn[i] == '\0')
		return (false);
	return (ft_strcmp(&(fn[i]), extension));
}

char	**read_map_file(const char *fn, int size)
{
	int		fd;
	char	**map;

	fd = open(fn, O_RDONLY);
	if (fd == -1)
	{
		perror("Failed opening map file while trying to load map");
		return (NULL);
	}
	map = (char **)malloc(sizeof(char *) * (size + 1));
	if (map == NULL)
		return (NULL);
	if (!alloc_map_lines(fd, map, size))
		return (NULL);
	if (close(fd) == -1)
	{
		perror("Failed closing map file after loading map lines");
		return (str_arr_free(map), NULL);
	}
	return (map);
}
