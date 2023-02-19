/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:48:17 by bvan-der          #+#    #+#             */
/*   Updated: 2022/10/13 12:18:00 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	uc;
	unsigned char	*c_ptr;

	if (len == 0UL)
		return (b);
	c_ptr = b;
	uc = c;
	i = 0;
	while (i < len)
	{
		c_ptr[i] = uc;
		i++;
	}
	return (c_ptr);
}
