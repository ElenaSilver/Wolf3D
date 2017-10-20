/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 04:15:00 by eserebry          #+#    #+#             */
/*   Updated: 2017/10/18 21:17:11 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		display_usage(t_env *env)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	str1 = "Press W, A, D, S or arrows to move";
	str2 = "Press space to jump";
	str3 = "Press H/M to hide/show this menu";
	str4 = "Press 1 2 3 4 5 to play music or 6 to stop music";
	mlx_string_put(env->mlx, env->win, 10, 5, 0x33ccff, "How to use:");
	mlx_string_put(env->mlx, env->win, 10, 25, 0x33ccff, str1);
	mlx_string_put(env->mlx, env->win, 10, 45, 0x33ccff, str2);
	mlx_string_put(env->mlx, env->win, 10, 65, 0x33ccff, str3);
	mlx_string_put(env->mlx, env->win, 10, 85, 0x33ccff, str4);
	mlx_string_put(env->mlx, env->win, 10, 105, 0x33ccff, "To exit: press ESC");
}

int			free_stuff(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img);
	free(env->win);
	free(env);
	system("killall afplay");
	return (1);
}

void		error_map(void)
{
	ft_putendl("wrong map");
	exit(1);
}
