/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:33:10 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/13 00:50:37 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_vars	vars;
	int		err_code;

	err_code = 1;
	if (!(vars.scene = scene_init()))
		return (print_err(-1, &vars));
	if (argc == 2)
	{
		if (!check_input_file(argv[1]))
			err_code = 0;
		err_code = minirt(argv[1], &vars);
	}
	else if (argc == 3)
	{
		if (ft_strcmp(argv[1], "--save"))
			err_code = -2;
		else if (!check_input_file(argv[2]))
			err_code = 0;
		else
			err_code = bitmap(argv[2], &vars);
	}
	if (err_code <= 0)
		return (print_err(err_code, &vars));
	return (0);
}
