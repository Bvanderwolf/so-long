/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:10:06 by bvan-der          #+#    #+#             */
/*   Updated: 2022/10/25 09:52:49 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_split(char **split, size_t split_i)
{
	size_t	i;

	i = 0UL;
	while (i < split_i)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	**alloc_split(const char *s, char c)
{
	size_t	i;
	size_t	size;
	char	**split;

	i = 0UL;
	size = 0UL;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			size++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else
		{
			i++;
		}
	}
	split = (char **)malloc((size + 1) * sizeof(char *));
	if (split == 0)
		return (0);
	return (split);
}

static char	**alloc_ranges(const char *s, char **split, char c)
{
	size_t	s_i;
	size_t	len;
	size_t	split_i;

	s_i = 0UL;
	split_i = 0UL;
	while (s[s_i] != '\0')
	{
		if (s[s_i] != c)
		{
			len = 0UL;
			while (s[s_i] != '\0' && s[s_i] != c && ++len)
				s_i++;
			split[split_i] = ft_substr(s, s_i - len, len);
			if (split[split_i] == NULL)
				return (free_split(split, split_i));
			split_i++;
		}
		else
			s_i++;
	}
	split[split_i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = alloc_split(s, c);
	if (split == NULL || alloc_ranges(s, split, c) == NULL)
		return (NULL);
	return (split);
}
