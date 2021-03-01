/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:53:59 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/01 16:02:27 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		handle_keypress(int keycode, t_vars *vars)
{
	if (keycode == KEY_X)
	{
		translate(vars->scene->world, X, PLUS);
		rendering(vars->scene, vars->img, vars);
	}
	else if (keycode == KEY_S)
	{
		scale(vars->scene->world, PLUS);
		rendering(vars->scene, vars->img, vars);
	}
}

void	handle_hook(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L<<0, handle_keypress, vars);
}
