/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:18:13 by bvan-der          #+#    #+#             */
/*   Updated: 2022/10/13 12:13:08 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*cpy_reverse(void *dst, const void *src, size_t len)
{
	int		i;
	char	*c_dst_ptr;
	char	*c_src_ptr;

	i = len - 1;
	c_dst_ptr = (char *)dst;
	c_src_ptr = (char *)src;
	while (i >= 0)
	{
		c_dst_ptr[i] = c_src_ptr[i];
		i--;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src)
		return (cpy_reverse(dst, src, len));
	return (ft_memcpy(dst, src, len));
}
