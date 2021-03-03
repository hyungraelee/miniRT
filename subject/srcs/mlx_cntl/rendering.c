/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:08:33 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/03 15:31:43 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rendering(t_vars *vars)
{
	int		i;
	int		j;
	double	u;
	double	v;
	int		rgb;

	j = vars->scene->canvas.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < vars->scene->canvas.width)
		{
			u = (double)i / (vars->scene->canvas.width - 1);
			v = (double)j / (vars->scene->canvas.height - 1);
			vars->scene->ray = ray_primary(&vars->scene->camera, u, v);
			rgb = create_rgb(ray_color(vars->scene));
			my_mlx_pixel_put(vars->img, i, vars->scene->canvas.height - j - 1, rgb);
			i++;
		}
		j--;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}
