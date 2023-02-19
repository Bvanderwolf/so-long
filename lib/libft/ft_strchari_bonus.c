/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchari_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:14:03 by bvan-der          #+#    #+#             */
/*   Updated: 2022/10/22 14:26:00 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_strchri(const char *s, int c)
{
	ssize_t	i;
	char	chr;

	if (s == NULL)
		return (-1L);
	i = 0L;
	chr = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == chr)
			return (i);
		i++;
	}
	if (chr == '\0')
		return (i);
	return (-1L);
}
