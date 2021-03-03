/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:33:10 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/03 15:34:13 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	t_vars	vars;

	parse_rt(argv[1], vars.scene);
	set_mlx(&vars);
	rendering(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
