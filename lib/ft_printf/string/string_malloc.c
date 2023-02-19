/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:58:17 by bvan-der          #+#    #+#             */
/*   Updated: 2022/12/28 10:18:17 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_ctostr(int c)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = (char)c;
	str[1] = '\0';
	return (str);
}
