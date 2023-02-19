/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_number_state.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:45:14 by bvan-der          #+#    #+#             */
/*   Updated: 2022/11/25 13:45:37 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	get_number_argument_length(t_cstate *state)
{
	int	len;

	len = ft_strlen(state->conversion);
	if (get_decimal_prefix(state) != NULL)
		len--;
	return (len);
}

int	get_precision_number_argument_length(t_cstate *state)
{
	int	len;

	len = ft_strlen(state->conversion);
	if (ft_atol(state->conversion) < 0)
		len--;
	return (len);
}

int	get_precision_modifier(t_cstate *state)
{
	int	arg_len;

	if (ft_strchr(NUMBER_CONVERSIONS, state->specifier) != NULL)
	{
		arg_len = get_precision_number_argument_length(state);
		if (state->precision <= arg_len)
			return (0);
		return (state->precision - arg_len);
	}
	else if (state->specifier == 's')
	{
		arg_len = ft_strlen(state->conversion);
		if (state->precision < arg_len)
			return (state->precision - arg_len);
	}
	return (0);
}
