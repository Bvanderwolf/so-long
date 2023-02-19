/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long_anim.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/03 15:51:15 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/18 18:02:51 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_ANIM_H
# define SO_LONG_ANIM_H

# include <stdbool.h>
# include "so_long.h"
# include "so_long_img.h"
# include "so_long_utils.h"
# include "../libft/libft.h"

# define ANIM_DELTA 0.07
# define DEFAULT_ANIM_START_INDEX 0
# define DEFAULT_ANIM_SPEED 1.0

# define MIN_GOBLIN_DECISION_TIME 1.0
# define MAX_GOBLIN_DECISION_TIME 2.0

# define MIN_SLIME_DECISION_TIME 2.0
# define MAX_SLIME_DECISION_TIME 2.5

# define MIN_FLY_DECISION_TIME 1.5
# define MAX_FLY_DECISION_TIME 2.0

typedef struct s_animation
{
	char			name[MAX_IMG_NAME_SIZE];
	double			start_time;
	int				frame;
	int				frame_count;
	float			speed;
	int				instance_index;
	mlx_image_t		*images[DEFAULT_ANIM_LEN + 1];
}				t_animation;

typedef struct s_animatable
{
	t_vector2	spawn_map_xy;
	t_list		*animations;
}			t_animatable;

typedef struct s_enemy
{
	t_vector2		world_xy;
	t_vector2		map_xy;
	t_vector2		look_direction;
	float			decision_time;
	float			current_decision_time;
	t_walk			*walk;
	t_animatable	*animatable;
}					t_enemy;

typedef struct s_effect
{
	int				frames_left;
	t_animatable	*animatable;
}					t_effect;

t_list			*create_animations(t_context *gc, const char *paths[], float speed);
t_animation		*create_animation(t_context *gc, const char *path, float speed);
void			animation_disable(t_animation *animation);
void			animation_enable(t_animation *animation);

t_animatable	*create_animatable(t_context *gc, t_vector2 pos, float speed, const char *paths[]);
void			free_animatable(void *animatable);
void			render_animatable(void *context);
t_animatable	*get_animatable(t_context *gc, t_vector2 spawn_map_xy);

t_enemy			*create_enemy(t_context *gc, t_vector2 map_xy, float decision_time, float speed, const char *paths[]);
t_enemy			*get_enemy(t_context *gc, t_vector2 spawn_map_xy);
void			free_enemy(void *enemy);

t_animation		*get_active_animation(t_list *animations);
int				get_animation_frame(t_animation *animation);
bool			is_disabled_animation(t_animation *animation);
void			append_animation_suffix(t_vector2 dir, const char *prefix, char name[]);
int				get_animation_seq(t_context *gc, const char *name, mlx_image_t *seq[]);
void			set_active_animation(t_list **animations, const char *name);
void			update_animation_image(t_animation *animation);
void			update_animation_position(t_animation *animation, t_vector2 new_position);

bool			animation_to_window(mlx_t *mlx, t_animation *animation, int32_t xy[2]);
bool			animations_to_window(mlx_t *mlx, t_list *animations, int32_t xy[2]);

#endif