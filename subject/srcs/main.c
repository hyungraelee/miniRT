/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:33:10 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/09 17:56:07 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

t_scene	*scene_init()
{
	t_scene	*scene;
	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL);
	// if (!(scene->world = (t_object *)malloc(sizeof(t_object))))
	// 	return (-1);
	scene->camera = NULL;
	scene->light = NULL;
	scene->world = NULL;
	return (scene);
}

int main(int argc, char *argv[])
{
	t_vars	vars;

	vars.scene = scene_init();

	// parse_rt(argv[1], vars.scene);
	// set_mlx(&vars);
	// rendering(&vars);
	// handle_hook(&vars);
	// mlx_loop(vars.mlx);
	// if (argc == 3 && ft_strcmp(argv[1], "--save"))
	// {

			parse_rt(argv[1], vars.scene);
			set_mlx_bmp(&vars);
			save_bitmap(&vars);
	// }
	// else
	// 	err;
	return (0);
}
