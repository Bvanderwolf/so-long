/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:13:59 by bvan-der          #+#    #+#             */
/*   Updated: 2022/11/25 13:50:14 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_cresult	cresult_failed(void)
{
	t_cresult	result;

	result.iterated = 0;
	result.printed = -1;
	return (result);
}

int	get_current_field_width(t_cstate *state)
{
	int	arg_len;

	arg_len = get_conversion_string_width(state);
	if ((state->specifier == 'i' || state->specifier == 'd')
		&& ((has_flag(state, BLANK_PREFIX | PLUS_PREFIX))
			&& ft_atoi(state->conversion) >= 0))
		arg_len++;
	else if ((state->specifier == 'x' || state->specifier == 'X')
		&& has_flag(state, ALTERNATE_FORM) && state->conversion[0] != '0')
		arg_len += 2;
	if (state->precision != -1)
		arg_len += get_precision_modifier(state);
	return (arg_len);
}

int	get_conversion_string_width(t_cstate *state)
{
	if (ft_strchr(NUMBER_CONVERSIONS, state->specifier) != NULL
		&& state->precision == 0 && state->conversion[0] == '0')
		return (0);
	if (state->specifier == 'c' && state->conversion[0] == '\0')
		return (1UL);
	return (ft_strlen(state->conversion));
}

int	has_flag(t_cstate *state, t_flag flags)
{
	if ((state->flags & flags) != 0)
		return (1);
	return (0);
}

int	reset_conversion_state(t_cstate **state)
{
	t_cstate	*set_state;

	if (*state == NULL)
	{
		*state = (t_cstate *)malloc(1 * sizeof(t_cstate));
		if (*state == NULL)
			return (0);
	}
	set_state = *state;
	set_state->flags = NO_FLAGS;
	set_state->precision = -1;
	set_state->width = 0;
	set_state->specifier = '\0';
	set_state->conversion = NULL;
	return (1);
}
