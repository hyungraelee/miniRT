/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:05:41 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/04 16:14:56 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_mlx(t_vars *vars)
{
	vars->img = (t_img *)malloc(sizeof(t_img));
	// 	// return (NULL);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "Gogi joa");
	vars->img->img = mlx_new_image(vars->mlx, vars->scene->canvas.width, vars->scene->canvas.height);
	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bits_per_pixel, &vars->img->line_length, &vars->img->endian);
}
