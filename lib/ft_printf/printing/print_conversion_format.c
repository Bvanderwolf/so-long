/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_format.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:42:54 by bvan-der          #+#    #+#             */
/*   Updated: 2022/11/25 14:02:22 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_zero_padding(t_cstate *state)
{
	int		padding;
	int		arg_len;

	if ((state->flags & ZERO_PADD) == 0 || state->precision != -1
		|| (state->flags & LEFT_ADJUST) != 0)
		return (0);
	arg_len = ft_strlen(state->conversion);
	if ((state->specifier == 'i' || state->specifier == 'd')
		&& ((has_flag(state, BLANK_PREFIX | PLUS_PREFIX))
			&& ft_atoi(state->conversion) >= 0))
		arg_len++;
	else if ((state->specifier == 'x' || state->specifier == 'X')
		&& has_flag(state, ALTERNATE_FORM) && state->conversion[0] != '0')
		arg_len += 2;
	if (state->width <= arg_len)
		return (0);
	padding = state->width - arg_len;
	return (print_padding(padding, "0"));
}

int	print_precision(t_cstate *state)
{
	int	padding;

	if (!has_flag(state, PRECISION)
		|| ft_strchr(NUMBER_CONVERSIONS, state->specifier) == NULL)
		return (0);
	padding = get_precision_modifier(state);
	if (padding <= 0)
		return (0);
	return (print_padding(padding, "0"));
}

int	print_conversion_string(t_cstate *state)
{
	size_t	nbytes;
	char	*buf;

	if (ft_strchr(NUMBER_CONVERSIONS, state->specifier) != NULL
		&& state->precision == 0 && state->conversion[0] == '0')
		return (0);
	buf = state->conversion;
	nbytes = ft_strlen(buf);
	if (state->specifier == 'c' && state->conversion[0] == '\0')
		nbytes = 1UL;
	if ((state->specifier == 'i' || state->specifier == 'd')
		&& ft_atoi(state->conversion) < 0)
	{
		buf++;
		nbytes -= 1UL;
	}
	if ((state->specifier == 's' && has_flag(state, PRECISION)
			&& (size_t)state->precision < nbytes))
		nbytes = (size_t)state->precision;
	return (write(1, buf, nbytes));
}
