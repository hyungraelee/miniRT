/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 23:52:08 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/13 01:05:06 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	print_err(int err_code, t_vars *vars)
{
	free_list(&vars->scene->world);
	free_list(&vars->scene->camera);
	free_list(&vars->scene->light);
	if (err_code == 0)
	{
		printf("%s\n!!!!! Error: Please check the \".rt\" file.\n\n", C_RED);
	}
	else if (err_code == -1)
		printf("%s\n!!!!! Error: Does not memory allocation.\n\n", C_RED);
	else if (err_code == -2)
		printf("%s\n!!!!! Error: Please check the input argument.\n\n", C_RED);
	free_scene(vars);
	return (0);
}
