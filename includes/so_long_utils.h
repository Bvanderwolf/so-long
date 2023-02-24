/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long_utils.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-der <bvan-der@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 10:29:58 by bvan-der      #+#    #+#                 */
/*   Updated: 2023/02/23 10:33:55 by bvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_UTILS_H
# define SO_LONG_UTILS_H

# include <stdlib.h>
# include <stdbool.h>
# include <libft.h>

typedef struct s_vector_2
{
	int	x;
	int	y;
}		t_vector2;

typedef struct s_walk
{
	t_vector2	target_world_xy;
	t_vector2	direction;
}				t_walk;

// Random

float		rand01(void);
float		rand_minmax(float min, float max);

// String

char		*str_arr_chr_pred(char **strs, int x, bool (*predicate)(int));
char		*strchr_pred(const char *str, bool (*predicate)(int));
size_t		str_arr_len(char **strs);
char		**str_arr_cpy(char **src, char **dst);
bool		ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(const char *dst, const char *src);
void		str_set_char(char str[2], char c);

char		**str_arr_dup(char **arr);
void		str_arr_free(char **arr);

void		lst_free(t_list **lst);
void		lst_mergeback(t_list **lst, t_list *range);

// Vector2

t_vector2	vector2_add_xy(t_vector2 v, int x, int y);
t_vector2	vector2_add(t_vector2 lhs, t_vector2 rhs);
t_vector2	vector2_new(int x, int y);
t_vector2	*vector2_alloc(int x, int y);
bool		vector2_equals(t_vector2 lhs, t_vector2 rhs);
bool		vector2_equals_xy(t_vector2 v, int x, int y);
int			vector2_sqr_distance(t_vector2 v1, t_vector2 v2);
void		vector2_arr_free(t_vector2 **arr);

// Walk

t_walk		*walk_alloc(t_vector2 target);
bool		walk_is_active(t_walk *walk);
void		walk_set_target(t_walk *walk, t_vector2 direction, t_vector2 from);

#endif