/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:20:48 by bvan-der          #+#    #+#             */
/*   Updated: 2022/10/20 15:22:43 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	src_size;
	char	*cpy;

	src_size = ft_strlen(s1) + 1;
	cpy = (char *)malloc(src_size * sizeof(char));
	if (cpy == 0)
		return (0);
	ft_strlcpy(cpy, s1, src_size);
	return (cpy);
}
