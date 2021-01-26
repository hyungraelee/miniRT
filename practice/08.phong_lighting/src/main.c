/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:51:31 by hyunlee           #+#    #+#             */
/*   Updated: 2021/01/26 14:22:56 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/utils.h"
#include "../include/scene.h"
#include "../include/trace.h"
#include "../include/print.h"

t_scene		*scene_init(void)
{
	t_scene		*scene;
	t_object	*world;
	t_object	*lights;

	// 추루 NULL이 아닌 적절한 에러 처리가 필요.
	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL);
	scene->canvas = canvas(400, 300);
	scene->camera = camera(&scene->canvas, point3(0, 0, 0));
	world = object(SP, sphere(point3(-2, 0, -5), 2));
	oadd(&world, (object(SP, sphere(point3(2, 0, -5), 2))));
	scene->world = world;
	lights = object(LIGHT_POINT, light_point(point3(3, 3, 0), color3(1, 0, 0), 0.5));
	scene->light = lights;
	return (scene);

}

int main()
{
	int			i;
	int			j;
	double		u;
	double		v;
	t_color3	pixel_color;
	t_scene		*scene;

	scene = scenen_init();

	printf("P3\n%d %d\n255\n", scene->canvas.width, scene->canvas.height);
	j = scene->canvas.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < scene->canvas.width)
		{
			u = (double)i / (scene->canvas.width - 1);
			v = (double)j / (scene->canvas.height - 1);
			scene->ray = ray_primary(&scene>camera, u, v);
			pixel_color = ray_color(scene);
			write_color(pixel_color);
			i++;
		}
		j--;
	}
	return (0);
}
