/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   line_count.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 11:06:06 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/09 12:08:35 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#include "so_long_map.h"
#include "ft_printf.h"

static int	count_newlines(int fd)
{
	int		i;
	int		line_c;
	int		last_char;
	char	buffer[1024];
	ssize_t	read_c;

	read_c = 1L;
	line_c = 0;
	while (read_c > 0)
	{
		read_c = read(fd, buffer, 1024);
		i = 0;
		while (i < read_c)
		{
			if (buffer[i] == '\n')
				line_c++;
			last_char = buffer[i];
			i++;
		}
	}
	if (read_c == -1)
		return (-1);
	if (last_char != '\n')
		line_c++;
	return (line_c);
}

int	count_lines(const char *fn)
{
	int		fd;
	int		line_c;

	fd = open(fn, O_RDONLY);
	if (fd == -1)
	{
		perror("Failed opening map file when trying to count map lines");
		return (-1);
	}
	line_c = count_newlines(fd);
	if (line_c == -1)
	{
		perror("Failed reading map file during map line count");
		return (-1);
	}
	if (close(fd) == -1)
	{
		perror("Failed closing map file after counting map lines");
		return (-1);
	}
	if (line_c < MIN_MAP_SIZE)
		return (ft_printf(NO_MIN_MAP_SIZE_MSG), -1);
	return (line_c);
}
