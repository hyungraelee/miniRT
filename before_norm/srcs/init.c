/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 23:56:13 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/11 23:56:32 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	*scene_init()
{
	t_scene	*scene;
	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL);
	scene->camera = NULL;
	scene->light = NULL;
	scene->world = NULL;
	scene->min_width = 480;
	scene->min_height = 480;
	return (scene);
}
