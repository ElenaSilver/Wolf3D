/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 17:52:00 by eserebry          #+#    #+#             */
/*   Updated: 2017/10/18 23:36:15 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WIDTH 1200
# define HEIGHT 800

# define KEY_UP 13
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_DOWN 1
# define KEY_JUMP 49
# define KEY_ESC 53
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ONE 83
# define TWO 84
# define THREE 85
# define FOUR 86
# define FIVE 87
# define SIX 88
# define H 4
# define M 46

# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include "../libft/includes/libft.h"

typedef struct		s_ixy
{
	int				x;
	int				y;
}					t_ixy;

typedef struct		s_dxy
{
	double			x;
	double			y;
}					t_dxy;

typedef struct		s_player
{
	struct s_dxy	pos;
	struct s_dxy	dir;
	struct s_dxy	plane;
	double			speed_turn;
	double			speed_move;
	int				z;
	char			is_jump;
	char			move_left;
	char			move_right;
	char			move_up;
	char			move_down;
	char			move_jump;
}					t_player;

typedef struct		s_ray
{
	struct s_dxy	pos;
	struct s_dxy	dir;
	struct s_dxy	side;
	struct s_dxy	delta;
	struct s_ixy	step;
	struct s_ixy	map;
	double			dist;
	double			cam;
	int				hit;
	int				hit_side;
}					t_ray;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*img_ptr;
	int				**map;
	char			*data;
	int				bpp;
	int				sline;
	int				endian;
	int				id;
	clock_t			last_frame;
	clock_t			next_frame;
	struct s_player	player;
	struct s_ray	ray;
	int				height;
	int				width;
	int				map_width;
	int				map_height;
	int				help;
	unsigned int	color_1;
	unsigned int	color_2;
	unsigned int	color_3;
	unsigned int	color_4;
	unsigned int	color_sky;
	unsigned int	color_ground;
}					t_env;

/*
** init.c
*/
t_env				*init_env(void);
/*
** key_management.c
*/
int					ft_key(int key, t_env *env);
void				music(int key);
int					ft_exit(t_env *e);
int					loop_hook(t_env *e);
/*
** main.c
*/
void				draw_line(t_env *e, int x, int start, int end);
/*
** map_init.c
*/
int					open_file(t_env *e, char *f);
/*
** menu.c
*/
void				display_usage(t_env *env);
int					free_stuff(t_env *env);
void				error_map(void);
/*
** movement.c
*/
void				move_left(t_env *e);
void				move_right(t_env *e);
void				move_forward(t_env *e);
void				move_backwards(t_env *e);
void				move_jump(t_env *e);
/*
** raycasting.c
*/
void				raycasting(t_env *e);

#endif
