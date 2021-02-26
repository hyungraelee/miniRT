/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:51:31 by hyunlee           #+#    #+#             */
/*   Updated: 2021/02/26 15:51:34 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/utils.h"
#include "../include/scene.h"
#include "../include/trace.h"
#include "../include/print.h"
#include "../include/trans.h"

t_scene		*scene_init(void)
{
	t_scene		*scene;
	t_object	*world;
	t_object	*lights;

	//추후 NULL?�� ?��?�� ?��?��?�� ?��?�� 처리�?? ?��?��.
	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL);
	scene->canvas = canvas(700, 700);
	scene->camera = camera(&scene->canvas, point3(0, 10, 15));
	// world = object(SP, sphere(point3(-2, 2, -5), 2), color3(0.5, 0, 0));
	// world = object(CY, cylinder(point3(6, -3, -7), vec3(0, 1, 0), 5.0, 6.0), color3(0.9, 0, 0.4));
	world = object(SQ, square(point3(-10, 2, -2), vec3(0, 0, 1), 4), color3(0.4, 1, 0.4));
	// world = object(PL, plane(point3(0, -20, 0), vec3(0, 1, 0)), color3(0, 1, 0));
	// oadd(&world, object(SP, sphere(point3(0, -1000, 0), 995), color3(1, 1, 1)));
	oadd(&world, object(PL, plane(point3(0, -20, 0), vec3(0, 1, 0)), color3(0, 1, 0)));
	oadd(&world, object(PL, plane(point3(30, 0, 0), vec3(-1, 0, 0)), color3(0, 0, 1)));
	oadd(&world, object(PL, plane(point3(-30, 0, 0), vec3(1, 0, 0)), color3(1, 0, 0)));
	oadd(&world, object(PL, plane(point3(0, 0, -20), vec3(0, 0, 1)), color3(1, 1, 1)));
	oadd(&world, object(PL, plane(point3(0, 21, 0), vec3(0, 1, 0)), color3(0, 1, 0)));
	oadd(&world, object(TR, triangle(point3(-2, 0, -5), point3(2, 0, 4), point3(0, 2, -3)), color3(0.5, 0.5, 0.5)));
	// oadd(&world, object(CY, cylinder(point3(6, -3, -7), vec3(1, 2, -3), 5.0, 6.0), color3(0.9, 0, 0.4)));
	// oadd(&world, object(SQ, square(point3(-10, 0, 0), vec3(0, 0, 1), 4), color3(0.2, 0.7, 0.3)));
	// oadd(&world, object(SQ, square(point3(-8, 0, -2), vec3(2, 0, 4), 4), color3(0.9, 0.8, 0.4)));
	// oadd(&world, object(SQ, square(point3(-10, 2, -2), vec3(0, 1, 1), 4), color3(0.4, 1, 1)));
	oadd(&world, object(SP, sphere(point3(2, 0, -5), 2), color3(0, 0.5, 0)));
	scene->world = world;
	lights = object(LIGHT_POINT, light_point(point3(0, 20, 5), color3(1, 1, 1), 0.5), color3(0, 0, 0)); // ?���?? albedo
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

	scene = scene_init();
	// translate(scene->world, Y, PLUS);
	// translate(scene->world, Y, PLUS);
	// translate(scene->world, Y, PLUS);
	// translate(scene->world, Y, PLUS);
	// translate(scene->world, Y, PLUS);
	// scale(scene->world, PLUS);
	// scale(scene->world, PLUS);
	// scale(scene->world, PLUS);
	// scale(scene->world, PLUS);
	// scale(scene->world, PLUS);
	rotate(scene->world, Y, PLUS);
	// rotate(scene->world, Y, PLUS);
	// rotate(scene->world, Y, PLUS);
	// rotate(scene->world, Y, PLUS);
	// rotate(scene->world, Y, PLUS);
	// rotate(scene->world, Y, PLUS);
	// rotate(scene->world, Y, PLUS);
	// rotate(scene->world, Y, PLUS);
	printf("P3\n%d %d\n255\n", scene->canvas.width, scene->canvas.height);
	j = scene->canvas.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < scene->canvas.width)
		{
			u = (double)i / (scene->canvas.width - 1);
			v = (double)j / (scene->canvas.height - 1);
			scene->ray = ray_primary(&scene->camera, u, v);
			pixel_color = ray_color(scene);
			write_color(pixel_color);
			i++;
		}
		j--;
	}
	return (0);
}
