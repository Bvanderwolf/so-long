/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:12:10 by bvan-der          #+#    #+#             */
/*   Updated: 2022/12/28 10:17:38 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONVERSIONS "cspdiuxX%"
# define NUMBER_CONVERSIONS "diuxX"
# define FLAGS "#0- +"

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# include "../libft/libft.h"

/*
1. NO_FLAGS			= 0  or 0000 0000
2. ALTERNATE_FORM	= 1  or 0000 0001
2. ZERO_PADD		= 2  or 0000 0010
3. LEFT_ADJUST		= 4  or 0000 0100
4. blank			= 8  or 0000 1000
5. plus				= 16 or 0001 0000
6. precision		= 32 or 0010 0000
*/
typedef enum e_flag
{
	NO_FLAGS		= 0,
	ALTERNATE_FORM	= (1 << 0),
	ZERO_PADD		= (1 << 1),
	LEFT_ADJUST		= (1 << 2),
	BLANK_PREFIX	= (1 << 3),
	PLUS_PREFIX		= (1 << 4),
	PRECISION		= (1 << 5)
}	t_flag;

typedef struct s_cstate
{
	t_flag	flags;
	int		width;
	int		precision;
	char	specifier;
	char	*conversion;
}	t_cstate;

typedef struct s_cresult
{
	int	printed;
	int	iterated;
}	t_cresult;

typedef int	(*t_printf)(t_cstate *);

/* MEMORY */

void		nfree(void *ptr);

/* PRINTING */

int			ft_printf(const char *str, ...);
int			print_conversion_arg(t_cstate *state);
int			print_decimal_prefix(t_cstate *state);
int			print_alternate_form(t_cstate *state);
int			print_left_padding(t_cstate *state);
int			print_zero_padding(t_cstate *state);
int			print_precision(t_cstate *state);
int			print_conversion_string(t_cstate *state);
int			print_end(t_cstate *state, int printed);
int			print_padding(int amount, const char *padding);
int			print_multiple(const t_printf *print_fns, int nbr, t_cstate *state);

/* CONVERSION */

int			reset_conversion_state(t_cstate **conversion);
int			parse_conversion_flags(const char *str, t_cstate *state);
char		*conversion_strdup(const char *s1);
char		*conversion_uitoh(va_list *args, t_cstate state);
const char	*get_decimal_prefix(t_cstate *state);
const char	*get_alternate_form_prefix(t_cstate *state);
int			has_flag(t_cstate *state, t_flag flags);
int			get_precision_modifier(t_cstate *state);
int			get_precision_number_argument_length(t_cstate *state);
int			get_number_argument_length(t_cstate *state);
int			get_conversion_string_width(t_cstate *state);
int			get_current_field_width(t_cstate *state);
t_cresult	cresult_failed(void);

/* STRING MALLOC */

char		*ft_ctostr(int c);
char		*ft_ultohex(unsigned long n);
char		*ft_uitoa(unsigned int n);
char		*ft_uitoh(unsigned int n, const char *hex_characters);

/* STRING QUERY */

size_t		ft_strlen(const char *s);
int			ft_unumlen(unsigned long n, int base);

/* DECIMAL */

long		ft_atol(const char *str);

#endif