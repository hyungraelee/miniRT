/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 23:57:35 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/11 23:57:52 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	minirt(char *argv, t_vars *vars)
{
	vars->mlx = mlx_init();
	mlx_get_screen_size(vars->mlx, &(vars->scene->max_width), &(vars->scene->max_height));
	if (!(parse_rt(argv, vars->scene)))
		return (0);
	if (!(set_mlx(vars)))
		return (-1);
	rendering(vars);
	if (!(handle_hook(vars)))
		return (-1);
	mlx_loop(vars->mlx);
	return (1);
}
