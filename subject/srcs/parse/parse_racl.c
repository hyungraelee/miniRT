/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_racl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 00:10:44 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 23:31:33 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	info_r(char **info, t_scene *scene)
{
	int	width;
	int	height;

	scene->cnt_r++;
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
	char		**tmp;
	t_color3	color;

	scene->cnt_a++;
	if (!check_err_a(info))
		return (0);
	tmp = ft_split(info[2], ',');
	color = color3(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_split(tmp);
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
	char		**tmp;

	scene->cnt_c++;
	if (!check_err_c(info))
		return (0);
	tmp = ft_split(info[1], ',');
	orig = point3(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_split(tmp);
	tmp = ft_split(info[2], ',');
	normal = point3(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_split(tmp);
	if (normal.x == 0 && normal.y == 0 && normal.z == 0)
		return (0);
	degrees = ft_atod(info[3]);
	oadd(&scene->camera, object(CAM, \
	camera(&scene->canvas, orig, normal, degrees), color3(0, 0, 0)));
	return (1);
}

int	info_l(char **info, t_scene *scene)
{
	t_point3	position;
	double		bright_ratio;
	t_color3	color;
	char		**tmp;

	scene->cnt_l++;
	if (!check_err_l(info))
		return (0);
	tmp = ft_split(info[1], ',');
	position = point3(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_split(tmp);
	bright_ratio = ft_atod(info[2]);
	tmp = ft_split(info[3], ',');
	color = color3(ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	free_split(tmp);
	if (!check_color(color))
		return (0);
	color = vdiv(color, 255.0);
	oadd(&scene->light, object(LIGHT_POINT, \
	light_point(position, color, bright_ratio), color3(0, 0, 0)));
	return (1);
}
