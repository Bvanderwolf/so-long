/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion_prefix.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:41:29 by bvan-der          #+#    #+#             */
/*   Updated: 2022/11/25 15:53:51 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_decimal_prefix(t_cstate *state)
{
	const char	*prefix;

	prefix = get_decimal_prefix(state);
	if (prefix != NULL)
		return (write(1, prefix, 1UL));
	return (0);
}

int	print_left_padding(t_cstate *state)
{
	int		padding;
	int		current_width;

	if (has_flag(state, LEFT_ADJUST)
		|| (has_flag(state, ZERO_PADD) && !has_flag(state, PRECISION)))
		return (0);
	current_width = get_current_field_width(state);
	if (state->width <= current_width)
		return (0);
	padding = state->width - current_width;
	return (print_padding(padding, " "));
}

int	print_alternate_form(t_cstate *state)
{
	const char	*str;

	if (!has_flag(state, ALTERNATE_FORM))
		return (0);
	str = get_alternate_form_prefix(state);
	if (str == NULL)
		return (0);
	if (state->conversion[0] == '0')
		return (0);
	return (write(1, str, 2UL));
}
