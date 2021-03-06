/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 17:51:24 by eserebry          #+#    #+#             */
/*   Updated: 2017/10/18 23:35:36 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			draw_pixel(t_env *env, int x, int y, unsigned int c)
{
	int		i;

	i = (x * 4) + (y * env->sline);
	env->data[i] = c;
	env->data[++i] = c >> 8;
	env->data[++i] = c >> 16;
}

unsigned int	walls_color(t_env *env)
{
	if (env->ray.hit_side == 1)
	{
		if ((env->ray.step.x == -1 && env->ray.step.y == -1) ||
			(env->ray.step.x == 1 && env->ray.step.y == -1))
			return (env->color_1);
		if ((env->ray.step.x == -1 && env->ray.step.y == 1) ||
			(env->ray.step.x == 1 && env->ray.step.y == 1))
			return (env->color_2);
	}
	if ((env->ray.step.x == -1 && env->ray.step.y == -1) ||
		(env->ray.step.x == -1 && env->ray.step.y == 1))
		return (env->color_3);
	return (env->color_4);
}

unsigned int	add_smog(unsigned int c, double d)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	red = c;
	green = c >> 8;
	blue = c >> 16;
	d = 7 / (100 / d);
	if (d > 0.9)
		d = 0.9;
	if (red > 0)
		red = red - (red * d);
	if (green > 0)
		green = green - (green * d);
	if (blue > 0)
		blue = blue - (blue * d);
	return ((red << 16) + (green << 8) + blue);
}

void			draw_line(t_env *env, int x, int start, int end)
{
	int				i;
	unsigned int	c;

	c = walls_color(env);
	c = add_smog(c, env->ray.dist);
	i = -1;
	while (++i < start + env->player.z)
		draw_pixel(env, x, i, env->color_sky);
	i--;
	while (++i <= end + env->player.z && i < env->height)
		draw_pixel(env, x, i, c);
	i--;
	while (++i < env->height)
		draw_pixel(env, x, i, add_smog(env->color_ground,
		abs(i - env->height) * 0.040));
}

int				main(int argc, char **argv)
{
	t_env	*env;

	env = init_env();
	if (argc != 2 || open_file(env, argv[1]) == 0)
	{
		ft_putendl("usage: ./wolf3d [maps/map_name]");
		exit(1);
	}
	env->mlx = mlx_init();
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->data = mlx_get_data_addr(env->img, &(env->bpp), &(env->sline),
			&(env->endian));
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Wolf3d eserebry");
	mlx_do_key_autorepeatoff(env->mlx);
	mlx_loop_hook(env->mlx, loop_hook, env);
	mlx_key_hook(env->win, ft_key, env);
	mlx_hook(env->win, 2, 0, ft_key, env);
	mlx_hook(env->win, 17, 0, ft_exit, env);
	mlx_loop(env->mlx);
	mlx_destroy_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img);
	free(env->win);
	free(env);
	return (0);
}
