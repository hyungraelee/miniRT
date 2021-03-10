/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:11:35 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/10 18:24:43 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

int	info_r(char	**info, t_scene *scene)
{
	int	width;
	int	height;

	if (!check_err_r(info))
		return (0);
	width = ft_atoi(info[1]);
	height = ft_atoi(info[2]);
	if (width < scene->min_width)
		width = scene->min_width;
	if (height < scene->min_height)
		height = scene->min_height;
	if (width > scene->max_width)
		width = scene->max_width;
	if (height > scene->max_height)
		height = scene->max_height;
	scene->canvas = canvas(width, height);
	return (1);
}

int	info_a(char **info, t_scene *scene)
{
	char	**element;
	t_color3	color;

	if (!check_err_a(info))
		return (0);
	element = ft_split(info[2], ',');
	color = color3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	if (!check_color(color))
		return (0);
	color = vdiv(color, 255.0);
	scene->ambient = ambient(ft_atod(info[1]), color);
	return (1);
}

int	info_c(char **info, t_scene *scene)
{
	t_point3	orig;
	t_vec3		normal;
	double		degrees;
	char		**element;

	if (!check_err_c(info))
		return (0);
	element = ft_split(info[1], ',');
	orig = point3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	element = ft_split(info[2], ',');
	normal = point3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	degrees = ft_atod(info[3]);
	oadd(&scene->camera, object(CAM, camera(&scene->canvas, orig, normal, degrees), color3(0, 0, 0)));
	return (1);
}

int	info_l(char **info, t_scene *scene)
{
	t_point3	position;
	double		bright_ratio;
	t_color3	color;
	char		**element;

	if (!check_err_l(info))
		return (0);
	element = ft_split(info[1], ',');
	position = point3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	bright_ratio = ft_atod(info[2]);
	element = ft_split(info[3], ',');
	color = color3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	if (!check_color(color))
		return (0);
	color = vdiv(color, 255.0);
	oadd(&scene->light, object(LIGHT_POINT, light_point(position, color, bright_ratio), color3(0, 0, 0)));
	return (1);
}

int	info_sp(char **info, t_scene *scene, t_object **world)
{
	t_point3	center;
	double		diameter;
	t_color3	color;
	char		**element;

	if (!check_err_sp(info))
		return (0);
	element = ft_split(info[1], ',');
	center = point3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	diameter = ft_atod(info[2]);
	element = ft_split(info[3], ',');
	color = color3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	if (!check_color(color))
		return (0);
	color = vdiv(color, 255.0);
	oadd(world, object(SP, sphere(center, diameter), color));
	return (1);
}

int	info_pl(char **info, t_scene *scene, t_object **world)
{
	t_point3	center;
	t_vec3		normal;
	t_color3	color;
	char		**element;

	if (!check_err_pl(info))
		return (0);
	element = ft_split(info[1], ',');
	center = point3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	element = ft_split(info[2], ',');
	normal = vec3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	element = ft_split(info[3], ',');
	color = color3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	if (!check_color(color))
		return (0);
	color = vdiv(color, 255.0);
	oadd(world, object(PL, plane(center, normal), color));
	return (1);
}

int	info_sq(char **info, t_scene *scene, t_object **world)
{
	t_point3	center;
	t_vec3		normal;
	double		length;
	t_color3	color;
	char		**element;

	if (!check_err_sq(info))
		return (0);
	element = ft_split(info[1], ',');
	center = point3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	element = ft_split(info[2], ',');
	normal = vec3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	length = ft_atod(info[3]);
	element = ft_split(info[4], ',');
	color = color3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	if (!check_color(color))
		return (0);
	color = vdiv(color, 255.0);
	oadd(world, object(SQ, square(center, normal, length), color));
	return(1);
}

int	info_cy(char **info, t_scene *scene, t_object **world)
{
	t_point3	center;
	t_vec3		normal;
	t_color3	color;
	char		**element;

	if (!check_err_cy(info))
		return (0);
	element = ft_split(info[1], ',');
	center = point3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	element = ft_split(info[2], ',');
	normal = vec3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	element = ft_split(info[5], ',');
	color = color3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	if (!check_color(color))
		return (0);
	color = vdiv(color, 255.0);
	oadd(world, object(CY, cylinder(center, normal, ft_atod(info[3]), ft_atod(info[4])), color));
	return (1);
}

int	info_tr(char **info, t_scene *scene, t_object **world)
{
	t_point3	a;
	t_point3	b;
	t_point3	c;
	t_color3	color;
	char		**element;

	if (!check_err_tr(info))
		return (0);
	element = ft_split(info[1], ',');
	a = point3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	element = ft_split(info[2], ',');
	b = point3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	element = ft_split(info[3], ',');
	c = point3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	element = ft_split(info[4], ',');
	color = color3(ft_atod(element[0]), ft_atod(element[1]), ft_atod(element[2]));
	free(element);
	if (!check_color(color))
		return (0);
	color = vdiv(color, 255.0);
	oadd(world, object(TR, triangle(a, b, c), color));
	return (1);
}

int	handle_info(char **info, t_scene *scene)
{
	if (!(check_info_err(info)))
		return (0);
	if (!(ft_strcmp(info[0], "R")))
		return(info_r(info, scene));
	else if (!(ft_strcmp(info[0], "A")))
		return(info_a(info, scene));
	else if (!(ft_strcmp(info[0], "c")))
		return(info_c(info, scene));
	else if (!(ft_strcmp(info[0], "l")))
		return(info_l(info, scene));
	else if (!(ft_strcmp(info[0], "sp")))
		return(info_sp(info, scene, &scene->world));
	else if (!(ft_strcmp(info[0], "pl")))
		return(info_pl(info, scene, &scene->world));
	else if (!(ft_strcmp(info[0], "sq")))
		return(info_sq(info, scene, &scene->world));
	else if (!(ft_strcmp(info[0], "cy")))
		return(info_cy(info, scene, &scene->world));
	else if (!(ft_strcmp(info[0], "tr")))
		return(info_tr(info, scene, &scene->world));
	else
		return (1);
}

int	parse_rt(char *argv, t_scene *scene)
{
	int		fd;
	int		ret;
	char	*line;
	char	**info;



	fd = open(argv, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		info = ft_split(line,' ');
		if (!handle_info(info, scene))
			return (0);
		free(line);
		free(info);
	}
	if (ret < 0)
		return (-1);
	return (1);
}
