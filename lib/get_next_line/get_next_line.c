/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:25:59 by bvan-der          #+#    #+#             */
/*   Updated: 2022/12/28 13:37:10 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
Joins history with the buffer used for reading characters.
Returns the joined history.
*/
static char	*join_history(char *history, const char *buffer)
{
	char	*joined_history;

	if (history == NULL)
	{
		joined_history = ft_strdup(buffer);
	}
	else
	{
		joined_history = strjoin(history, buffer);
		free (history);
	}
	return (joined_history);
}

/*
Trims the history by trimming away the first newline encountered
and any characters before it.
Returns the pointer to the history argument to be updated.
*/
static char	*trim_history(char *history)
{
	unsigned int	start;
	size_t			new_len;
	char			*old_history;

	start = 0U;
	while (history[start] != '\n')
		start++;
	new_len = 0UL;
	while (history[start + new_len] != '\0')
		new_len++;
	old_history = history;
	history = ft_substr(history, start + 1, new_len);
	free (old_history);
	return (history);
}

/*
Reads th next line from the given fd, updating the history with
characters read into the buffer.
Returns the last amount of characters read using the buffer.
*/
static ssize_t	read_next_line(int fd, char **history)
{
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		read_count;

	read_count = 1;
	while (strchr(*history, '\n') == NULL && read_count != 0)
	{
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count == -1)
		{
			if (*history != NULL)
			{
				free(*history);
				*history = NULL;
			}
			return (-1L);
		}
		if (read_count > 0)
		{
			buffer[read_count] = '\0';
			*history = join_history(*history, buffer);
			if (*history == NULL)
				return (-1L);
		}
	}
	return (read_count);
}

/*
Reads BUFFER_SIZE bytes from the given file descriptor until it
finds a new line to return.
Returns 0 if there is nothing else to read or an error occured during reading.
*/
char	*get_next_line(int fd)
{
	static char	*history;
	char		*next_line;
	ssize_t		read_count;

	read_count = read_next_line(fd, &history);
	if (read_count == -1)
		return (NULL);
	if (read_count > 0 || (history != NULL && history[0] == '\n'))
	{
		next_line = ft_substr(history, 0, ft_strtlen(history, '\n') + 1);
		history = trim_history(history);
		if (history == 0)
			return (0);
		return (next_line);
	}
	if (history != NULL && history[0] != '\0')
		next_line = ft_strdup(history);
	else
		next_line = NULL;
	free(history);
	history = NULL;
	return (next_line);
}
