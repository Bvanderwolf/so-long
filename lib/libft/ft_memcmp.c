/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:43:46 by bvan-der          #+#    #+#             */
/*   Updated: 2022/10/13 12:09:41 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*uc_ptr1;
	unsigned char	*uc_ptr2;

	i = 0;
	uc_ptr1 = (unsigned char *)s1;
	uc_ptr2 = (unsigned char *)s2;
	while (i < n)
	{
		if (uc_ptr1[i] != uc_ptr2[i])
			return (uc_ptr1[i] - uc_ptr2[i]);
		i++;
	}
	return (0);
}
