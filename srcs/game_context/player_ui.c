/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_ui.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 12:39:52 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 17:06:26 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"
#include "so_long_img.h"

void	update_player_steps_ui(t_context *gc)
{
	char	*number;
	t_text	*text;

	number = ft_itoa(gc->player->steps);
	if (number == NULL)
		exit_clearing_context(gc);
	text = find_text(gc->text, STEPS_TEXT);
	update_text_value(text, number);
	update_window_with_text(gc, text);
	ft_printf("total steps %s\n", number);
	free(number);
}
