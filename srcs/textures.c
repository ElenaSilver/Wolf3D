/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 05:50:20 by eserebry          #+#    #+#             */
/*   Updated: 2017/10/17 05:55:47 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	load_textures(t_env *env)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	env->img = mlx_xmp_file_to_image(env-mlx, "textures/redbrick.xmp", &a, &b)
	env->data = mlx_get_data_addr(env->img, &env->bpp, &env->sline, &env->endian);
}
