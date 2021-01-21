/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:51:31 by hyunlee           #+#    #+#             */
/*   Updated: 2021/01/21 21:01:22 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/utils.h"
#include "../include/scene.h"
#include "../include/trace.h"
#include "../include/color.h"

int main()
{
	int			i;
	int			j;
	double		u;
	double		v;
	t_color3	pixel_color;
	t_canvas	canv;
	t_camera	cam;
	t_ray		ray;
	t_object	*world;

	canv = canvas(400, 300);
	cam = camera(&canv, point3(0, 0, 0));
	world = object(SP, sphere(point3(0, 0, -5), 2));

	printf("P3\n%d %d\n255\n", canv.width, canv.height);
	j = canv.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < canv.width)
		{
			u = (double)i / (canv.width - 1);
			v = (double)j / (canv.height - 1);
			ray = ray_primary(&cam, u, v);
			pixel_color = ray_color(&ray, &sp);
			write_color(pixel_color);
			i++;
		}
		j--;
	}
	return (0);
}
