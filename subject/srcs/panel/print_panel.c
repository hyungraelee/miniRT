/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_panel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:14:29 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/11 18:14:30 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_panel(t_vars *vars)
{
	top_bottom_panel();
	object_panel(vars->mode->selected);
	next_previous_panel(vars->mode->selected);
	transform_panel(vars->mode->trans);
	axis_panel(vars->mode->axis);
	top_bottom_panel();
}
