/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:52:55 by bvan-der          #+#    #+#             */
/*   Updated: 2022/12/28 13:36:20 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*strchr(const char *s, int c)
{
	int		i;
	char	chr;

	if (s == NULL)
		return (NULL);
	i = 0;
	chr = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == chr)
			return ((char *)(&s[i]));
		i++;
	}
	if (chr == '\0')
		return ((char *)(&s[i]));
	return (NULL);
}

char	*strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*joined_str;

	i = 0;
	s1_len = ft_strtlen(s1, '\0');
	s2_len = ft_strtlen(s2, '\0');
	joined_str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (joined_str == NULL)
		return (NULL);
	while (i < s1_len)
	{
		joined_str[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		joined_str[i] = s2[i - s1_len];
		i++;
	}
	joined_str[i] = '\0';
	return (joined_str);
}
