/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:33:10 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/03 18:54:10 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	t_vars	vars;

	parse_rt(argv[1], vars.scene);
	printf("%d\n", vars.scene->canvas.width);
	set_mlx(&vars);
	rendering(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
