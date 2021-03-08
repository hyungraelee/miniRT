/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:33:10 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/08 18:05:24 by hyunlee          ###   ########.fr       */
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
	if (argc == 2 && ft_strncmp(ft_strrev(argv[1]), "tr.", 3))
	{
		parse_rt(argv[1], vars.scene);
		set_mlx(&vars);
		rendering(&vars);
		handle_hook(&vars);
		mlx_loop(vars.mlx);
	}
	else if (argc == 3 && ft_strcmp(argv[1], "--save"))
	{
		if (ft_strncmp(ft_strrev(argv[2]), "tr.", 3))
		{
			parse_rt(argv[2], vars.scene);
			rendering_bmp(vars);
		}
	}
	// else
	// 	err;
	return (0);
}
