/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:37:17 by bvan-der          #+#    #+#             */
/*   Updated: 2022/11/25 13:44:24 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_end(t_cstate *state, int printed)
{
	free(state);
	return (printed);
}

int	print_padding(int amount, const char *padding)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		if (write(1, padding, 1UL) == -1)
			return (-1);
		i++;
	}
	return (amount);
}

int	print_multiple(const t_printf *print_fns, int nbr, t_cstate *state)
{
	int				i;
	int				total_printed;
	int				printed;

	i = 0;
	total_printed = 0;
	while (i < nbr)
	{
		printed = print_fns[i](state);
		if (printed == -1)
			return (-1);
		total_printed += printed;
		i++;
	}
	return (total_printed);
}
