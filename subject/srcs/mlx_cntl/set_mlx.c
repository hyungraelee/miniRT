/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:05:41 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 00:24:11 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	set_mlx(t_vars *vars)
{
	if (!(vars->img = (t_img *)malloc(sizeof(t_img))))
		return (0);
	vars->win = mlx_new_window(vars->mlx, \
	vars->scene->canvas.width, vars->scene->canvas.height, "Gogi joa");
	vars->img->img = mlx_new_image(vars->mlx, \
	vars->scene->canvas.width, vars->scene->canvas.height);
	vars->img->addr = mlx_get_data_addr(vars->img->img, \
	&vars->img->bits_per_pixel, &vars->img->line_length, &vars->img->endian);
	return (1);
}
