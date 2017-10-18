/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 05:50:20 by eserebry          #+#    #+#             */
/*   Updated: 2017/10/18 02:57:06 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	load_textures(t_env *env)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	env->text[0].img = mlx_xpm_file_to_image(env->mlx, "textures/redbrick.xmp", &a, &b);
	env->text[0].data = mlx_get_data_addr(env->text[0].img, &env->text[0].bpp,
				&env->text[0].sizeline, &env->text[0].endian);
	env->text[1].img = mlx_xpm_file_to_image(env->mlx, "textures/mossy.xmp", &a, &b);
	env->text[1].data = mlx_get_data_addr(env->text[1].img, &env->text[1].bpp,
				&env->text[1].sizeline, &env->text[1].endian);
	env->text[2].img = mlx_xpm_file_to_image(env->mlx, "textures/sand.xmp", &a, &b);
	env->text[2].data = mlx_get_data_addr(env->text[2].img, &env->text[2].bpp,
				&env->text[2].sizeline, &env->text[2].endian);
	env->text[3].img = mlx_xpm_file_to_image(env->mlx, "textures/stone.xmp", &a, &b);
	env->text[3].data = mlx_get_data_addr(env->text[3].img, &env->text[3].bpp,
				&env->text[3].sizeline, &env->text[3].endian);
}

/*
** texturing calculations
** 64 - width of the texture, x coordinate on the texture
** 256 and 128 factors to avoid floats
** id - represent text[]
*/

static void		calc_textures(int x, int start, int end, t_env *env)
{
	if (env->texture == 1)
	{
		env->id = env->map[env->ray.map.x][env->ray.map.y] - 1;
		if (env->side == 0) 
			env->wall_x = env->ray.pos.y + env->wall_dist * env->ray.dir.y;
		else
			env->wall_x = env->ray.pos.x + env->wall_dist * env->ray.dir.x;
		env->ray.text.x = (int)(env->wall_x * (double)(64));
		if(env->side == 0 && env->ray.dir.x > 0) 
			env->ray.text.x = 64 - env->ray.text.x - 1;
		if(env->side == 1 && env->ray.dir.y < 0) 
			env->ray.text.x = 64 - env->ray.text.x - 1;
		env->ray.text.x = abs(env->ray.text.x);
     }
     while (++start <= end)
     	put_pxl_to_image(env, x, start, env->color);
}
 
void	put_pxl_to_image(t_env *env, int x, int y, int color)
{
	int		d;

	if (env->texture == 1 && x < env->map_width && y < env->map_height)
	{
		d = abs((((y * 256 - env->map_height * 128 + env->lineheight * 128))));
		env->ray.text.y = ((d * 64) / env->lineheight) / 256;
		ft_memcpy(env->img_ptr + 4 * env->map_height * y + x * 4,
				&env->text[env->id].data[env->ray.text.y % 64 * env->text[env->id].sizeline +
				env->ray.text.x % 64 * env->text[env->id].bpp / 8], sizeof(int)); 
	}
	else if (x < env->map_height && y < env->map_height)
		ft_memcpy(env->img_ptr + 4 * env->map_height * y + x * 4,
				&color, sizeof(int));
}
