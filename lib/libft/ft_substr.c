/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:28:35 by bvan-der          #+#    #+#             */
/*   Updated: 2022/10/28 17:25:28 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	substr_i;
	size_t	s_i;
	char	*substr;

	substr = (char *)malloc((len + 1UL) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	substr_i = 0;
	s_i = 0;
	while (s[s_i] != '\0')
	{
		if (s_i >= start && substr_i < len)
		{
			substr[substr_i] = s[s_i];
			substr_i++;
		}
		s_i++;
	}
	substr[substr_i] = '\0';
	return (substr);
}
