/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 00:49:41 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 01:00:10 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	del_flag_in_selected(t_vars *vars)
{
	vars->mode->trans = OFF;
	vars->mode->axis = OFF;
	vars->mode->sign = OFF;
}

void	del_flag_in_trans(t_vars *vars)
{
	vars->mode->axis = OFF;
	vars->mode->sign = OFF;
}

void	transform_scene(t_vars *vars)
{
	if (vars->mode->trans == TRANSLATE)
	{
		translate(vars->cur, vars->mode->axis, vars->mode->sign);
		if (vars->cur->type == CAM)
			make_viewport(vars->cur->element);
	}
	else if (vars->mode->trans == ROTATE)
	{
		rotate(vars->cur, vars->mode->axis, vars->mode->sign);

		if (vars->cur->type == CAM)
			make_viewport(vars->cur->element);
	}
	else if (vars->mode->trans == SCALE)
		scale(vars->cur, vars->mode->sign);
	rendering(vars);
}
