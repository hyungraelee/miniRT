/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis_panel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:14:05 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/11 18:14:10 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	default_axis(void)
{
	printf("+\t\t\t\t\t       +\n");
	printf("#\t\t\t\t\t       #\n");
	printf(":     %s %s  %s %s\t      %s %s  %s %s\t      %s    %s     :\n", B_WHT, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET);
	printf("+      %s  %s\t      %s    %s\t\t%s %s      +\n", B_WHT, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET);
	printf("#     %s %s  %s %s\t       %s  %s\t       %s %s       #\n", B_WHT, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET);
	printf(":     %s %s  %s %s\t       %s  %s\t      %s    %s     :\n", B_WHT, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET);
	printf("+\t\t\t\t\t       +\n");
	printf("#\t\t\t\t\t       #\n");
	printf(":----------------------------------------------:\n");
}

void	selected_x(void)
{
	printf("+\t\t\t\t\t       +\n");
	printf("#   %s        %s\t\t\t\t       #\n", B_PRPL, B_RESET);
	printf(":   %s  %s %s  %s %s  %s\t      %s %s  %s %s\t      %s    %s     :\n", B_PRPL, B_WHT, B_PRPL, B_WHT, B_PRPL, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET);
	printf("+   %s   %s  %s   %s\t      %s    %s\t\t%s %s      +\n", B_PRPL, B_WHT, B_PRPL, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET);
	printf("#   %s  %s %s  %s %s  %s\t       %s  %s\t       %s %s       #\n", B_PRPL, B_WHT, B_PRPL, B_WHT, B_PRPL, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET);
	printf(":   %s  %s %s  %s %s  %s\t       %s  %s\t      %s    %s     :\n", B_PRPL, B_WHT, B_PRPL, B_WHT, B_PRPL, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET);
	printf("+   %s        %s\t\t\t\t       +\n", B_PRPL, B_RESET);
	printf("#\t\t\t\t\t       #\n");
	printf(":----------------------------------------------:\n");
}

void	selected_y(void)
{
	printf("+\t\t\t\t\t       +\n");
	printf("#\t\t    %s        %s\t\t       #\n", B_PRPL, B_RESET);
	printf(":     %s %s  %s %s\t    %s  %s %s  %s %s  %s\t      %s    %s     :\n", B_WHT, B_RESET, B_WHT, B_RESET, B_PRPL, B_WHT, B_PRPL, B_WHT, B_PRPL, B_RESET, B_WHT, B_RESET);
	printf("+      %s  %s\t    %s  %s    %s  %s\t\t%s %s      +\n", B_WHT, B_RESET, B_PRPL, B_WHT, B_PRPL, B_RESET, B_WHT, B_RESET);
	printf("#     %s %s  %s %s\t    %s   %s  %s   %s\t       %s %s       #\n", B_WHT, B_RESET, B_WHT, B_RESET, B_PRPL, B_WHT, B_PRPL, B_RESET, B_WHT, B_RESET);
	printf(":     %s %s  %s %s\t    %s   %s  %s   %s\t      %s    %s     :\n", B_WHT, B_RESET, B_WHT, B_RESET, B_PRPL, B_WHT, B_PRPL, B_RESET, B_WHT, B_RESET);
	printf("+\t\t    %s        %s\t\t       +\n", B_PRPL, B_RESET);
	printf("#\t\t\t\t\t       #\n");
	printf(":----------------------------------------------:\n");
}

void	selected_z(void)
{
	printf("+\t\t\t\t\t       +\n");
	printf("#\t\t\t\t    %s        %s   #\n", B_PRPL, B_RESET);
	printf(":     %s %s  %s %s\t      %s %s  %s %s\t    %s  %s    %s  %s   :\n", B_WHT, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET, B_PRPL, B_WHT, B_PRPL, B_RESET);
	printf("+      %s  %s\t      %s    %s\t    %s    %s %s   %s   +\n", B_WHT, B_RESET, B_WHT, B_RESET, B_PRPL, B_WHT, B_PRPL, B_RESET);
	printf("#     %s %s  %s %s\t       %s  %s\t    %s   %s %s    %s   #\n", B_WHT, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET, B_PRPL, B_WHT, B_PRPL, B_RESET);
	printf(":     %s %s  %s %s\t       %s  %s\t    %s  %s    %s  %s   :\n", B_WHT, B_RESET, B_WHT, B_RESET, B_WHT, B_RESET, B_PRPL, B_WHT, B_PRPL, B_RESET);
	printf("+\t\t\t\t    %s        %s   +\n", B_PRPL, B_RESET);
	printf("#\t\t\t\t\t       #\n");
	printf(":----------------------------------------------:\n");
}

void	axis_panel(int axis)
{
	if (axis == OFF)
		default_axis();
	else if (axis == X)
		selected_x();
	else if (axis == Y)
		selected_y();
	else if (axis == Z)
		selected_z();
}
