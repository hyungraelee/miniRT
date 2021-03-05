/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:14:09 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/05 17:09:43 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// int		control_light(int keycode, t_vars *vars)
// {
// 	if (keycode == KEY_T)
// 	{
// 		mlx_hook(vars->win, 2, 1L<<0, tra)
// 	}
// }

int		translate_camera(int keycode, t_vars *vars)
{
	int	axis;
	int	sign;

	if (keycode == KEY_W)
	{
		printf("selected W\n");
		axis = Y;
		sign = PLUS;
	}
	else if (keycode == KEY_S)
	{
		printf("selected S\n");
		axis = Y;
		sign = MINUS;
	}
	else if (keycode == KEY_Q)
	{
		return (0);
	}
	vars->scene->camera->orig = translate_center(vars->scene->camera->orig, axis, sign);
	rendering(vars);
	return (1);
}

int		control_camera(int keycode, t_vars *vars)
{
	if (keycode == KEY_T)
	{
		printf("selected T\n");
		mlx_hook(vars->win, 2, 1L<<0, translate_camera, vars);
	}
	return (1);
}

int		select_scene(int keycode, t_vars *vars)
{
	// if (keycode == KEY_L)
	// {
		// mlx_hook(vars->win, 2, 1L<<0, control_light, vars);
	// }
	// else
	if (keycode == KEY_C)
	{
		printf("selected C\n");
		mlx_hook(vars->win, 2, 1L<<0, control_camera, vars);
	}
// 	else if (keycode == KEY_O)
	return (1);
}

int		handle_keypress(int keycode, t_vars *vars)
{
	if (keycode == KEY_L || keycode == KEY_C || keycode == KEY_O)
		select_scene(keycode, vars);
	return (1);
}

void	handle_hook(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L<<0, handle_keypress, vars);
}
