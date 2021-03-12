/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 23:56:13 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 23:25:58 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	*scene_init(void)
{
	t_scene	*scene;

	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL);
	scene->camera = NULL;
	scene->light = NULL;
	scene->world = NULL;
	scene->min_width = 480;
	scene->min_height = 480;
	scene->cnt_r = 0;
	scene->cnt_a = 0;
	scene->cnt_c = 0;
	scene->cnt_l = 0;
	return (scene);
}
