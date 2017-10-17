/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 18:15:28 by eserebry          #+#    #+#             */
/*   Updated: 2017/10/17 03:30:21 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ray_draw(t_env *env, int x)
{
	int		height;
	int		start;
	int		end;

	height = (int)(env->height / env->ray.dist);
	start = -height / 2 + env->height / 2;
	if (start < 0)
		start = 0;
	end = height / 2 + env->height / 2;
	if (end >= env->height)
		end = env->height - 1;
	draw_line(env, x, start, end);
}

static void		ray_cal_dist(t_env *e)
{
	while (e->ray.hit == 0)
	{
		if (e->ray.side.x < e->ray.side.y)
		{
			e->ray.side.x += e->ray.delta.x;
			e->ray.map.x += e->ray.step.x;
			e->ray.hit_side = 0;
		}
		else
		{
			e->ray.side.y += e->ray.delta.y;
			e->ray.map.y += e->ray.step.y;
			e->ray.hit_side = 1;
		}
		if (e->map[e->ray.map.x][e->ray.map.y] > 0)
		{
			e->ray.hit = 1;
			if (e->ray.hit_side == 0)
				e->ray.dist = (e->ray.map.x - e->ray.pos.x + (1 - e->ray.step.x)
						/ 2) / e->ray.dir.x;
			else
				e->ray.dist = (e->ray.map.y - e->ray.pos.y + (1 - e->ray.step.y)
						/ 2) / e->ray.dir.y;
		}
	}
}

static void		ray_cal_step_side(t_env *e)
{
	if (e->ray.dir.x < 0)
	{
		e->ray.step.x = -1;
		e->ray.side.x = (e->ray.pos.x - (int)e->ray.pos.x) * e->ray.delta.x;
	}
	else
	{
		e->ray.step.x = 1;
		e->ray.side.x = ((int)e->ray.pos.x + 1 - e->ray.pos.x) * e->ray.delta.x;
	}
	if (e->ray.dir.y < 0)
	{
		e->ray.step.y = -1;
		e->ray.side.y = (e->ray.pos.y - (int)e->ray.pos.y) * e->ray.delta.y;
	}
	else
	{
		e->ray.step.y = 1;
		e->ray.side.y = ((int)e->ray.pos.y + 1 - e->ray.pos.y) * e->ray.delta.y;
	}
}

static void		ray_init(t_env *env, int x)
{
	env->ray.map.x = (int)env->ray.pos.x;
	env->ray.map.y = (int)env->ray.pos.y;
	env->ray.cam = 2 * x / (double)env->width - 1;
	env->ray.dir.x = env->player.dir.x + env->player.plane.x * env->ray.cam;
	env->ray.dir.y = env->player.dir.y + env->player.plane.y * env->ray.cam;
	env->ray.delta.x = sqrt(1 + (env->ray.dir.y * env->ray.dir.y) /
			(env->ray.dir.x * env->ray.dir.x));
	env->ray.delta.y = sqrt(1 + (env->ray.dir.x * env->ray.dir.x) /
			(env->ray.dir.y * env->ray.dir.y));
	env->ray.hit = 0;
	env->ray.dist = -1;
	env->ray.hit_side = -1;
}

void			raycasting(t_env *env)
{
	int		x;

	x = -1;
	env->ray.pos.x = env->player.pos.x;
	env->ray.pos.y = env->player.pos.y;
	while (++x < env->width)
	{
		ray_init(env, x);
		ray_cal_step_side(env);
		ray_cal_dist(env);
		ray_draw(env, x);
	}
}
