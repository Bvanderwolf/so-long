/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:59:22 by bvan-der          #+#    #+#             */
/*   Updated: 2022/10/29 16:51:54 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0UL)
		return (0);
	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && i < (n - 1UL))
	{
		if ((unsigned char)s1[i] == (unsigned char)s2[i] && s1[i] == '\0')
			return (0);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
