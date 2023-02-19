/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchari_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:25:06 by bvan-der          #+#    #+#             */
/*   Updated: 2022/10/22 14:29:42 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_strrchri(const char *s, int c)
{
	ssize_t	i;
	ssize_t	last_i;
	char	chr;

	if (s == NULL)
		return (-1L);
	i = 0L;
	last_i = -1L;
	chr = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == chr)
			last_i = i;
		i++;
	}
	if (chr == '\0')
		last_i = i;
	return (last_i);
}
