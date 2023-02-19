/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtlen_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:08:37 by bvan-der          #+#    #+#             */
/*   Updated: 2022/12/28 15:26:28 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strtlen(const char *s, char t)
{
	size_t	i;

	if (s == NULL)
		return (0UL);
	i = 0;
	while (s[i] != t && s[i] != '\0')
		i++;
	return (i);
}
