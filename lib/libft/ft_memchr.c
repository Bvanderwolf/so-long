/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:24:24 by bvan-der          #+#    #+#             */
/*   Updated: 2022/10/18 12:55:38 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*uc_ptr;
	char	chr;

	i = 0;
	uc_ptr = (char *)s;
	chr = (char)c;
	while (i < n)
	{
		if (uc_ptr[i] == chr)
			return (&((void *)uc_ptr)[i]);
		i++;
	}
	return (0);
}
