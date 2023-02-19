/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_malloc_number.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:33:14 by bvan-der          #+#    #+#             */
/*   Updated: 2022/12/28 10:18:06 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_uitoh(unsigned int n, const char *hex_characters)
{
	int		len;
	char	*str;
	int		i;

	len = ft_numlen(n, 16);
	i = len - 1;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i] = hex_characters[n % 16];
		n /= 16;
		i--;
	}
	return (str);
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*str;
	int		i;

	len = ft_numlen(n, 10);
	i = len - 1;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (str);
}

char	*ft_ultohex(unsigned long n)
{
	const char	*hex_characters = "0123456789abcdef";
	char		*str;
	int			len;
	int			i;

	len = ft_unumlen(n, 16) + 2;
	i = len - 1;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	str[0] = '0';
	str[1] = 'x';
	if (n == 0UL)
		str[2] = '0';
	while (n != 0UL)
	{
		str[i] = hex_characters[n % 16];
		n /= 16;
		i--;
	}
	return (str);
}
