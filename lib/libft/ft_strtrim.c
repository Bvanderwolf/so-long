/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:10:34 by bvan-der          #+#    #+#             */
/*   Updated: 2022/10/25 09:50:35 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_contains(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	char		*trim_str;
	size_t		start;
	size_t		end;

	start = 0UL;
	i = 0UL;
	while (s1[start] != '\0' && str_contains(set, s1[start]) == 1)
		start++;
	end = ft_strlen(s1);
	while (end > start && str_contains(set, s1[end - 1]) == 1)
		end--;
	trim_str = (char *)malloc((end - start + 1) * sizeof(char));
	if (trim_str == NULL)
		return (NULL);
	while (start < end)
	{
		trim_str[i] = s1[start];
		i++;
		start++;
	}
	trim_str[i] = '\0';
	return (trim_str);
}
