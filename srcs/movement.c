/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 17:15:30 by eserebry          #+#    #+#             */
/*   Updated: 2017/10/18 20:59:23 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** move forvard if there is no walls in front of you
*/

void	move_forward(t_env *e)
{
	if (e->map[(int)(e->player.pos.x + e->player.dir.x * e->player.speed_move)]
			[(int)e->player.pos.y] == 0)
		e->player.pos.x += e->player.dir.x * e->player.speed_move;
	if (e->map[(int)e->player.pos.x][(int)(e->player.pos.y + e->player.dir.y *
				e->player.speed_move)] == 0)
		e->player.pos.y += e->player.dir.y * e->player.speed_move;
}

/*
** move backwards if there is no walls in front of you
*/

void	move_backwards(t_env *e)
{
	if (e->map[(int)(e->player.pos.x - e->player.dir.x * e->player.speed_move)]
			[(int)e->player.pos.y] == 0)
		e->player.pos.x -= e->player.dir.x * e->player.speed_move;
	if (e->map[(int)e->player.pos.x][(int)(e->player.pos.y - e->player.dir.y *
				e->player.speed_move)] == 0)
		e->player.pos.y -= e->player.dir.y * e->player.speed_move;
}

/*
** rotate both camera plane and camera direction to the right
*/

void	move_right(t_env *e)
{
	t_dxy	old;

	old.x = e->player.dir.x;
	e->player.dir.x = e->player.dir.x * cos(-e->player.speed_turn) -
		e->player.dir.y * sin(-e->player.speed_turn);
	e->player.dir.y = old.x * sin(-e->player.speed_turn) + e->player.dir.y *
		cos(-e->player.speed_turn);
	old.x = e->player.plane.x;
	e->player.plane.x = e->player.plane.x * cos(-e->player.speed_turn) -
		e->player.plane.y * sin(-e->player.speed_turn);
	e->player.plane.y = old.x * sin(-e->player.speed_turn) + e->player.plane.y *
		cos(-e->player.speed_turn);
}

/*
** rotate both camera plane and camera direction to the left
*/

void	move_left(t_env *e)
{
	t_dxy	old;

	old.x = e->player.dir.x;
	e->player.dir.x = e->player.dir.x * cos(e->player.speed_turn) -
		e->player.dir.y * sin(e->player.speed_turn);
	e->player.dir.y = old.x * sin(e->player.speed_turn) + e->player.dir.y *
		cos(e->player.speed_turn);
	old.x = e->player.plane.x;
	e->player.plane.x = e->player.plane.x * cos(e->player.speed_turn) -
		e->player.plane.y * sin(e->player.speed_turn);
	e->player.plane.y = old.x * sin(e->player.speed_turn) + e->player.plane.y *
		cos(e->player.speed_turn);
}

void	move_jump(t_env *env)
{
	if (env->player.z >= 100)
		env->player.is_jump = 1;
	if (env->player.is_jump == 1)
		env->player.z -= 10;
	if (env->player.is_jump == 0)
		env->player.z += 10;
	if (env->player.is_jump == 1 && env->player.z == 0)
	{
		env->player.is_jump = 0;
		env->player.move_jump = 0;
	}
}
