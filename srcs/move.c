/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 17:51:24 by eserebry          #+#    #+#             */
/*   Updated: 2017/10/18 04:44:42 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_key(int key, t_env *env)
{
	if (key == KEY_UP || key == ARROW_UP)
		env->player.move_up = !env->player.move_up;
	if (key == KEY_DOWN || key == ARROW_DOWN)
		env->player.move_down = !env->player.move_down;
	if (key == KEY_LEFT || key == ARROW_LEFT)
		env->player.move_left = !env->player.move_left;
	if (key == KEY_RIGHT || key == ARROW_RIGHT)
		env->player.move_right = !env->player.move_right;
	if (key == KEY_JUMP && env->player.move_jump == 0)
		{
			env->player.move_jump = 1;
			system("afplay music/jump.mp3&");
		}
	if (key == ONE || key == TWO || key == THREE || key == FOUR || key == FIVE)
		music(key);
	if (key == SIX)
		system("killall afplay");
	if (key == KEY_ESC)
	{
		ft_exit(env);
	}
		else if (key == 17)
	{
		if (env->texture == 0)
			env->texture = 1;
		else
			env->texture = 0;
	}
	if (key == 4)
	{
		if (env->help == 0)
			env->help = 1;
		else
			env->help = 0;
	}
	return (0);
}

void	music(int key)
{
	system("killall afplay");
	if (key == ONE)
		system("afplay music/Super_Mario_Bros.mp3&");
	if (key == TWO)
		system("afplay music/A_Ha_Take_On_Me.mp3&");
	if (key == THREE)
		system("afplay music/Kola_Kid_Press_Start.mp3&");
	if (key == FOUR)
		system("afplay music/Super_Mario_Bros_Remix.mp3&");
	if (key == FIVE)
		system("afplay music/Kola_Kid_2punk2suck.mp3&");
}

int		ft_exit(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	system("killall afplay");
	exit(0);
}

int		loop_hook(t_env *env)
{
	env->last_frame = clock();
	if (env->next_frame > env->last_frame)
		return (0);
	env->next_frame = env->last_frame + (CLOCKS_PER_SEC / 90);
	if (env->player.move_up)
		move_up(env);
	if (env->player.move_down)
		move_down(env);
	if (env->player.move_right)
		move_right(env);
	if (env->player.move_left)
		move_left(env);
	if (env->player.move_jump == 1)
		move_jump(env);
	if (env->help == 1)
		display_usage(env);
	raycasting(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}
