/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_query.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 11:40:31 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/01/27 15:53:41 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

bool	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return (false);
		if (s1[i + 1] == '\0' && s2[i + 1] != '\0')
			return (false);
		i++;
	}
	return (true);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = src[i];
	return (dst);
}

char	*strchr_pred(const char *str, bool (*predicate)(int))
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (predicate(str[i]))
			return ((char *)(&str[i]));
		i++;
	}
	return (NULL);
}
