/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:21:47 by bvan-der          #+#    #+#             */
/*   Updated: 2022/10/18 17:24:25 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_i;

	dest_i = 0;
	while (dst[dest_i] != '\0' && dest_i < dstsize)
		dest_i++;
	dest_i += ft_strlcpy(&dst[dest_i], src, dstsize - dest_i);
	return (dest_i);
}
