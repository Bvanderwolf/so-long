/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:28:30 by bvan-der          #+#    #+#             */
/*   Updated: 2022/11/25 13:29:54 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	parse_flags(const char *str, t_cstate *state)
{
	int		i;
	char	c;

	i = 0;
	while (ft_strchr(FLAGS, str[i]) != NULL)
	{
		c = str[i];
		if (c == '#')
			state->flags |= ALTERNATE_FORM;
		else if (c == '0')
			state->flags |= ZERO_PADD;
		else if (c == '-')
			state->flags |= LEFT_ADJUST;
		else if (c == ' ')
			state->flags |= BLANK_PREFIX;
		else if (c == '+')
			state->flags |= PLUS_PREFIX;
		i++;
	}
	return (i);
}

static int	parse_field_width(const char *str, t_cstate *state)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (ft_isdigit(str[i]))
	{
		width = ((width * 10) + (str[i] - '0'));
		i++;
	}
	state->width = width;
	return (i);
}

static int	parse_precision(const char *str, t_cstate *state)
{
	int	i;
	int	precision;

	i = 0;
	if (str[i] != '.')
		return (0);
	i++;
	precision = 0;
	while (ft_strchr(CONVERSIONS, str[i]) == NULL)
	{
		precision = ((precision * 10) + (str[i] - '0'));
		i++;
	}
	state->precision = precision;
	state->flags |= PRECISION;
	return (i);
}

int	parse_conversion_flags(const char *str, t_cstate *state)
{
	int	i;

	i = 1;
	i += parse_flags(&str[i], state);
	i += parse_field_width(&str[i], state);
	i += parse_precision(&str[i], state);
	if (ft_strchr(CONVERSIONS, str[i]) != NULL)
	{
		state->specifier = str[i];
		i++;
	}
	return (i);
}
