/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 17:51:24 by eserebry          #+#    #+#             */
/*   Updated: 2017/10/18 23:33:25 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		init_color_etc(t_env *env)
{
	env->color_1 = 0xFF0000;
	env->color_2 = 0x00CC00;
	env->color_3 = 0x0000FF;
	env->color_4 = 0x00FFFF;
	env->color_sky = 0xCCFFFF;
	env->color_ground = 0xE6E6E6;
	env->bpp = 0;
	env->sline = 0;
	env->help = 1;
	env->last_frame = clock();
	env->next_frame = 0;
	env->width = WIDTH;
	env->height = HEIGHT;
}

t_env			*init_env(void)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	env->player.pos.x = 0;
	env->player.pos.y = 0;
	env->player.dir.x = -1;
	env->player.dir.y = 0;
	env->player.z = 0;
	env->player.plane.x = 0;
	env->player.plane.y = 0.66;
	env->player.speed_turn = 0.05;
	env->player.speed_move = 0.05;
	env->player.move_up = 0;
	env->player.move_down = 0;
	env->player.move_right = 0;
	env->player.move_left = 0;
	env->player.move_jump = 0;
	env->player.is_jump = 0;
	init_color_etc(env);
	return (env);
	free(env);
}
