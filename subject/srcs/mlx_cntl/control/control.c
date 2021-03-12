/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:14:09 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/13 03:58:52 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_all(vars);
	exit(0);
}

int			handle_keypress(int keycode, t_vars *vars)
{
	keypress_obj(keycode, vars);
	keypress_np(keycode, vars);
	keypress_transform(keycode, vars);
	keypress_axis(keycode, vars);
	keypress_sign(keycode, vars);
	if (keycode == KEY_ESCAPE)
		close_window(vars);
	print_panel(vars);
	return (1);
}

int			handle_hook(t_vars *vars)
{
	if (!(vars->mode = (t_mode *)malloc(sizeof(t_mode))))
		return (0);
	vars->mode->selected = OFF;
	vars->mode->trans = OFF;
	vars->mode->axis = OFF;
	vars->mode->sign = OFF;
	print_panel(vars);
	mlx_hook(vars->win, 2, 0, handle_keypress, vars);
	mlx_hook(vars->win, 17, 0, close_window, vars);
	return (1);
}
