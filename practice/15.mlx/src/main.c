/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:51:31 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/01 15:41:26 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minirt.h"
#include "../lib/mlx/mlx.h"

t_scene		*scene_init(void)
{
	t_scene		*scene;
	t_object	*world;
	t_object	*lights;

	//추후 NULL?�� ?��?�� ?��?��?�� ?��?�� 처리�?? ?��?��.
	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL);
	scene->canvas = canvas(1500, 900);
	scene->camera = camera(&scene->canvas, point3(0, 2, 15));
	world = object(SP, sphere(point3(-2, 2, -5), 2), color3(0.5, 0, 0));
	// world = object(CY, cylinder(point3(6, -3, -7), vec3(0, 1, 0), 5.0, 6.0), color3(0.9, 0, 0.4));
	// world = object(SQ, square(point3(-10, 2, -2), vec3(0, 0, 1), 4), color3(0.4, 1, 0.4));
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

// int		close(int keycode, t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// }

// int		write_keycode(int keycode, t_vars *vars)
// {
// 	printf("keycode = %d\n", keycode);
// }

int main()
{
	// int			i;
	// int			j;
	// double		u;
	// double		v;
	// t_color3	pixel_color;
	t_scene		*scene;
	t_data		img;
	// int			mlx_color;
	t_vars		vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "MLX_PRACTICE");
	img.img = mlx_new_image(vars.mlx, 1500, 900);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);


	scene = scene_init();
	// printf("P3\n%d %d\n255\n", scene->canvas.width, scene->canvas.height);
	rendering(scene, &img, &vars);
	// j = scene->canvas.height - 1;
	// while (j >= 0)
	// {
	// 	i = 0;
	// 	while (i < scene->canvas.width)
	// 	{
	// 		u = (double)i / (scene->canvas.width - 1);
	// 		v = (double)j / (scene->canvas.height - 1);
	// 		scene->ray = ray_primary(&scene->camera, u, v);
	// 		pixel_color = ray_color(scene);
	// 		// write_color(pixel_color);
	// 		mlx_color = create_rgb(&pixel_color);
	// 		my_mlx_pixel_put(&img, i, scene->canvas.height - j - 1, mlx_color);
	// 		i++;
	// 	}
	// 	j--;
	// }
	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	vars.scene = scene;
	vars.img = &img;
	handle_hook(&vars);
	// mlx_hook(vars.win, 2, 1L<<0, write_keycode, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
