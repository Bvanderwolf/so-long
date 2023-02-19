/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:34:44 by bvan-der          #+#    #+#             */
/*   Updated: 2022/11/25 14:00:31 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define PRINTER_COUNT 3

static int	print_conversion_prefix(t_cstate *state)
{
	const t_printf	printers[PRINTER_COUNT] = {
		print_left_padding,
		print_decimal_prefix,
		print_alternate_form
	};

	return (print_multiple(printers, PRINTER_COUNT, state));
}

static int	print_conversion_format(t_cstate *state)
{
	const t_printf	printers[PRINTER_COUNT] = {
		print_zero_padding,
		print_precision,
		print_conversion_string
	};

	return (print_multiple(printers, PRINTER_COUNT, state));
}

static int	print_conversion_suffix(t_cstate *state)
{
	int		padding;
	int		current_width;

	if (!has_flag(state, LEFT_ADJUST))
		return (0);
	current_width = get_current_field_width(state);
	if (state->width <= current_width)
		return (0);
	padding = state->width - current_width;
	return (print_padding(padding, " "));
}

int	print_conversion_arg(t_cstate *state)
{
	const t_printf	printers[PRINTER_COUNT] = {
		print_conversion_prefix,
		print_conversion_format,
		print_conversion_suffix
	};

	if (state->conversion == NULL)
		return (-1);
	return (print_multiple(printers, PRINTER_COUNT, state));
}
