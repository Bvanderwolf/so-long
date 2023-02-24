/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 10:53:54 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 15:16:55 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "../libft/libft.h"
#include "so_long.h"
#include "so_long_map.h"
#include "ft_printf.h"
#include "so_long_img.h"
#include "MLX42/MLX42.h"

static bool	init_context(t_context *gc, const char *fn)
{
	char	**map;
	int		size;

	if (!check_file_extension(fn))
		return (ft_printf(INVALID_FILE_EXT), false);
	size = count_lines(fn);
	if (size == -1)
		return (false);
	map = read_map_file(fn, size);
	if (map == NULL)
		return (false);
	if (!validate_map_content(map))
		return (str_arr_free(map), false);
	if (!load_map_into_context(gc, map))
		return (str_arr_free(map), false);
	return (true);
}

static bool	init_mlx(t_context *gc)
{
	mlx_t	*mlx;
	int		width;
	int		height;

	width = gc->map->width * TILE_SIZE;
	height = (gc->map->height * TILE_SIZE) + WALL_HEIGHT + GUI_HEIGHT;
	mlx = mlx_init(width, height, "so long", false);
	if (mlx == NULL)
		return (ft_printf("Failed initializing mlx"), false);
	gc->mlx = mlx;
	return (true);
}

int	main(int argc, char *argv[])
{
	t_context	*gc;

	if (argc != 2)
	{
		ft_printf("Failed starting program: argument count is not 2\n");
		return (EXIT_FAILURE);
	}
	gc = (t_context *)ft_calloc(1, sizeof(t_context));
	if (gc == NULL)
		return (perror("Failed starting program"), EXIT_FAILURE);
	if (!init_context(gc, argv[1]) || !init_mlx(gc))
	{
		free(gc);
		exit(EXIT_FAILURE);
	}
	if (!game_init(gc))
		exit_clearing_context(gc);
	mlx_loop(gc->mlx);
	game_terminate(gc);
}
