/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:08:33 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/03 00:09:41 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rendering(t_scene *scene, t_data *img, t_vars *vars)
{
	int		i;
	int		j;
	double	u;
	double	v;
	int		rgb;

	j = scene->canvas.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < scene->canvas.width)
		{
			u = (double)i / (scene->canvas.width - 1);
			v = (double)j / (scene->canvas.height - 1);
			scene->ray = ray_primary(&scene->camera, u, v);
			rgb = create_rgb(ray_color(scene));
			my_mlx_pixel_put(img, i, scene->canvas.height - j - 1, rgb);
			i++;
		}
		j--;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
}
