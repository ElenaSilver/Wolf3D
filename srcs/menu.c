/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 04:15:00 by eserebry          #+#    #+#             */
/*   Updated: 2017/10/18 04:26:36 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		display_usage(t_env *env)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = "Press W, A, D, S or arrows to move";
	str2 = "Press space to jump";
	str3 = "Press H to hide this menu";
	mlx_string_put(env->mlx, env->win, 10, 5, 0xFFFFFF, "How to use:");
	mlx_string_put(env->mlx, env->win, 10, 25, 0xFFFFFF, str1);
	mlx_string_put(env->mlx, env->win, 10, 45, 0xFFFFFF, str2);
	mlx_string_put(env->mlx, env->win, 10, 65, 0xFFFFFF, str3);
	mlx_string_put(env->mlx, env->win, 10, 85, 0xFFFFFF, "To exit: press ESC");
}
