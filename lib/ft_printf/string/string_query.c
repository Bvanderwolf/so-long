/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_query.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:24:56 by bvan-der          #+#    #+#             */
/*   Updated: 2022/12/28 10:18:33 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_unumlen(unsigned long n, int base)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}
