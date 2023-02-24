/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long_img.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 13:51:45 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 12:55:54 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_IMG_H
# define SO_LONG_IMG_H

# include "so_long.h"
# include "MLX42/MLX42.h"

# define MAX_IMG_NAME_SIZE 50
# define MAX_TILE_LAYERS 2

# define IMG_ROOF_CORNER_BOTTOM_LEFT "roof_corner_bottom_left"
# define IMG_ROOF_CORNER_BOTTOM_RIGHT "roof_corner_bottom_right"
# define IMG_ROOF_CORNER_TOP_LEFT "roof_corner_top_left"
# define IMG_ROOF_CORNER_TOP_RIGHT "roof_corner_top_right"
# define IMG_ROOF_RIGHT "roof_right"
# define IMG_ROOF_LEFT "roof_left"
# define IMG_ROOF_BOTTOM "roof_bottom"
# define IMG_ROOF_TOP "roof_top"
# define IMG_KEG_WALL "keg_wall"
# define IMG_CLOSET_WALL "closet_wall"
# define IMG_SHORT_TABLE_WALL "short_table_wall"
# define IMG_LONG_TABLE_WALL_LEFT "long_table_wall_left"
# define IMG_LONG_TABLE_WALL_RIGHT "long_table_wall_right"

# define IMG_BANNER_RED "banner_red"
# define IMG_BANNER_GREEN "banner_green"
# define IMG_BANNER_SKELETON "banner_skeleton"
# define IMG_TORCH "torch"

# define IMG_FLOOR "floor_default"
# define IMG_FLOOR_ONE "floor_default_one"
# define IMG_FLOOR_TWO "floor_default_two"
# define IMG_FLOOR_THREE "floor_default_three"
# define IMG_FLOOR_FOUR "floor_default_four"
# define IMG_FLOOR_FIVE "floor_default_five"
# define IMG_FLOOR_SIX "floor_default_six"
# define IMG_FLOOR_SEVEN "floor_default_seven"
# define IMG_FLOOR_TOP_LEFT "floor_top_left"
# define IMG_FLOOR_TOP "floor_top"
# define IMG_FLOOR_TOP_RIGHT "floor_top_right"
# define IMG_FLOOR_RIGHT "floor_right"
# define IMG_FLOOR_LEFT "floor_left"

# define IMG_PANEL_TOP_LEFT "panel_top_left"
# define IMG_PANEL_TOP_RIGHT "panel_top_right"
# define IMG_PANEL_TOP "panel_top"
# define IMG_PANEL_MIDDLE_LEFT "panel_middle_left"
# define IMG_PANEL_MIDDLE_RIGHT "panel_middle_right"
# define IMG_PANEL_MIDDLE "panel_middle"
# define IMG_PANEL_BOTTOM_LEFT "panel_bottom_left"
# define IMG_PANEL_BOTTOM_RIGHT "panel_bottom_right"
# define IMG_PANEL_BOTTOM "panel_bottom"
# define IMG_PANEL_KNOB "panel_knob"

# define COLLECTED_TEXT "collected:"
# define STEPS_TEXT "steps:"

# define PANEL_MARGIN 15
# define PANEL_PADDING 5
# define PANEL_TEXT_SPACING 6
# define TEXT_SPACING 11
# define TEXT_RIGHT_OFFSET 26

# define IMG_WALL "wall"
# define IMG_EXIT "exit"
# define IMG_KEY "key"
# define IMG_GOLD "gold"

# define DEFAULT_ANIM_LEN 6
# define SHORT_ANIM_LEN 4

# define MAX_TEXT_LENGTH 100
# define ALPHA_CHAR_COUNT 26
# define NUMBER_AND_EQUAL_CHAR_COUNT 10
# define TEXT_CHAR_COUNT 36

/// @brief defines an image used in the game exposing its name and mlx image.
typedef struct s_image
{
	char		name[MAX_IMG_NAME_SIZE];
	mlx_image_t	*value;
}				t_image;

typedef struct s_layout
{
	int	x;
	int	y;
	int	width;
	int	height;
}		t_layout;

typedef struct s_text
{
	char		name[MAX_IMG_NAME_SIZE];
	t_vector2	world_xy;
	char		value[MAX_TEXT_LENGTH];
	t_image		*images[TEXT_CHAR_COUNT + 1];
	int			length;
	int			instances[MAX_TEXT_LENGTH];
}				t_text;

typedef void	(*t_img_unload)(mlx_t *, mlx_image_t *);

typedef void	(*t_tile_load)(t_context *gc, mlx_texture_t *texture, \
int number, char *name);

t_vector2		number_coordinates(mlx_texture_t *texture, \
int number, int size);
const char		*image_path_to_name(const char *path);
void			sequence_name(const char *base, char *name, \
int i, size_t *length);

mlx_image_t		*find_mlx_image(t_list *images, char *name);
t_image			*find_image(t_list *images, char *name);
mlx_instance_t	*find_instance_xy(t_list *images, int x, int y);

t_text			*create_text(t_context *gc, const char *name, \
const char *value);
t_text			*find_text(t_list *text, const char *name);
void			update_text_value(t_text *text, const char *value);
bool			update_window_with_text(t_context *gc, t_text *text);

t_image			*load_img_xy(mlx_t *mlx, mlx_texture_t *texture, \
uint32_t xy[2], int size);
t_image			*load_img_number(mlx_t *mlx, mlx_texture_t *texture, \
int number, int size);
bool			load_tile_sheet(t_context *gc, const char *name, \
mlx_texture_t *texture, int sheet_length);
bool			load_tile(t_context *gc, mlx_texture_t *texture, \
int number, char *name);
bool			load_text(t_context *gc, mlx_texture_t *texture, \
int number, char *name);
bool			load_sheets_at_paths(t_context *gc, const char *paths[], \
int sheet_length);

bool			load_numbers_and_equals_images(t_context *gc, \
mlx_texture_t *texture);
bool			load_alphabet_images(t_context *gc, mlx_texture_t *texture);

bool			load_player_image(t_context *gc);
bool			load_tile_images(t_context *gc);
bool			load_wall_images(t_context *gc, mlx_texture_t *texture);
bool			load_floor_images(t_context *gc, mlx_texture_t *texture);
bool			load_prop_images(t_context *gc, mlx_texture_t *texture);
bool			load_enemy_images(t_context *gc);
bool			load_ui_images(t_context *gc);

void			unload_images(t_context *gc, t_img_unload unload);
bool			load_images(t_context *gc);
void			free_mlx_img(mlx_t *mlx, mlx_image_t *image);

#endif