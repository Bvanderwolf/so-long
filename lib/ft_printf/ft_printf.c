/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:37:19 by bvan-der          #+#    #+#             */
/*   Updated: 2022/11/25 17:52:19 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_conversion_string(t_cstate *state, va_list *args)
{
	if (state->specifier == 'c')
		state->conversion = ft_ctostr(va_arg(*args, int));
	else if (state->specifier == 's')
		state->conversion = conversion_strdup(va_arg(*args, char *));
	else if (state->specifier == 'p')
		state->conversion = ft_ultohex(va_arg(*args, unsigned long));
	else if (state->specifier == 'd' || state->specifier == 'i')
		state->conversion = ft_itoa(va_arg(*args, int));
	else if (state->specifier == 'u')
		state->conversion = ft_uitoa(va_arg(*args, unsigned int));
	else if (state->specifier == 'x' || state->specifier == 'X')
		state->conversion = conversion_uitoh(args, *state);
	else if (state->specifier == '%')
		state->conversion = ft_ctostr('%');
}

static t_cresult	print_conversion(const char *s, t_cstate **st, va_list *ar)
{
	t_cresult	result;

	if (!reset_conversion_state(st))
		return (cresult_failed());
	result.iterated = parse_conversion_flags(s, *st);
	if (result.iterated == 1)
	{
		result.printed = 0;
	}
	else if ((*st)->specifier == '\0')
	{
		result.printed = 0;
		result.iterated = 1;
	}
	else
	{
		set_conversion_string(*st, ar);
		result.printed = print_conversion_arg(*st);
		nfree((*st)->conversion);
	}
	return (result);
}

static t_cresult	print_single(char c)
{
	t_cresult	result;

	result.printed = write(1, &c, 1UL);
	result.iterated = 1;
	return (result);
}

static int	print_str(const char *str, va_list *args)
{
	unsigned int	i;
	unsigned int	printed;
	t_cstate		*state;
	t_cresult		presult;

	i = 0U;
	printed = 0U;
	state = NULL;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			presult = print_single(str[i]);
		else
			presult = print_conversion(&str[i], &state, args);
		if (presult.printed == -1)
			return (print_end(state, -1));
		printed += presult.printed;
		i += presult.iterated;
	}
	return (print_end(state, printed));
}

int	ft_printf(const char *str, ...)
{
	int		printed;
	va_list	args;

	va_start(args, str);
	printed = print_str(str, &args);
	va_end(args);
	return (printed);
}
