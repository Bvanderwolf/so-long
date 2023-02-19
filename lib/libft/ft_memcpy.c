/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:52:04 by bvan-der          #+#    #+#             */
/*   Updated: 2022/10/13 12:11:51 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*c_dst_ptr;
	char	*c_src_ptr;

	i = 0;
	c_dst_ptr = (char *)dst;
	c_src_ptr = (char *)src;
	while (i < n)
	{
		c_dst_ptr[i] = c_src_ptr[i];
		i++;
	}
	return (dst);
}
