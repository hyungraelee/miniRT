/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:45:36 by hyunlee           #+#    #+#             */
/*   Updated: 2021/02/10 14:39:00 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/structures.h"
#include "../../include/scene.h"

t_object	*object(t_object_type type, void *element, t_color3 albedo)
{
	t_object	*new;

	if (!(new = (t_object *)malloc(sizeof(t_object))))
		return (NULL);
	new->type = type;
	new->element = element;
	new->next = NULL;
	new->albedo = albedo;
	return (new);
}

t_sphere	*sphere(t_point3 center, double radius)
{
	t_sphere	*sp;

	if (!(sp = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	sp->center = center;
	sp->radius = radius;
	sp->radius2 = radius * radius;
	return (sp);
}

t_plane		*plane(t_point3 center, t_vec3 normal)
{
	t_plane	*pl;

	if (!(pl = (t_plane *)malloc(sizeof(t_plane))))
		return (NULL);
	pl->center = center;
	pl->normal = normal;
	return (pl);
}

t_triangle	*triangle(t_point3 a, t_point3 b, t_point3 c)
{
	t_triangle	*tr;
	t_vec3		ab;
	t_vec3		ac;

	if (!(tr = (t_triangle *)malloc(sizeof(t_triangle))))
		return (NULL);
	tr->a = a;
	tr->b = b;
	tr->c = c;
	ab = vsub(b, a);
	ac = vsub(c, a);
	tr->normal = vcross(ab, ac);
	return (tr);
}

t_cylinder	*cylinder(t_point3 center, t_vec3 normal, double diameter, double height)
{
	t_cylinder	*cy;

	if (!(cy = (t_cylinder *)malloc(sizeof(t_cylinder))))
		return (NULL);
	cy->center = center;
	cy->normal = normal;
	cy->diameter = diameter;
	cy->radius = diameter / 2;
	cy->radius2 = cy->radius * cy->radius;
	cy->height = height;
	return (cy);
}

t_square	*square(t_point3 center, t_vec3 normal, double length)
{
	t_square	*sq;

	if (!(sq = (t_square *)malloc(sizeof(t_square))))
		return (NULL);
	sq->center = center;
	sq->normal = vunit(normal);
	if (fabs(sq->normal.x) == 1 && sq->normal.y == 0 && sq->normal.z == 0)
		sq->vertex = vec3(0, 1, 1);
	else if (sq->normal.x == 0 && fabs(sq->normal.y) == 1 && sq->normal.z == 0)
		sq->vertex = vec3(1, 0, 1);
	else if (sq->normal.x == 0 && sq->normal.y == 0 && fabs(sq->normal.z) == 1)
		sq->vertex = vec3(1, 1, 0);
	else
		return (NULL); // 나중에 리턴 다시 제대로 체크하기.
	// 올바른 법선이 아닌 경우 해당 square만 넘기면 되는데 NULL로 인해서 프로그램이 종료되지 않도록.
	sq->length = length;
	return (sq);
}

t_light		*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio)
{
	t_light	*light;

	if (!(light = (t_light *)malloc(sizeof(t_light))))
		return (NULL);
	light->origin = light_origin;
	light->light_color = light_color;
	light->bright_ratio = bright_ratio;
	return (light);
}
