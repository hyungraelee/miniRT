/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_objs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:57:11 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 15:57:53 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*sphere(t_point3 center, double diameter)
{
	t_sphere	*sp;

	if (!(sp = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	sp->center = center;
	sp->diameter = diameter;
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

t_square	*square(t_point3 center, t_vec3 normal, double length)
{
	t_square	*sq;

	if (!(sq = (t_square *)malloc(sizeof(t_square))))
		return (NULL);
	sq->center = center;
	sq->normal = vunit(normal);
	sq->length = length;
	return (sq);
}

t_cylinder	*cylinder(t_point3 center, t_vec3 norm, double diameter, double h)
{
	t_cylinder	*cy;

	if (!(cy = (t_cylinder *)malloc(sizeof(t_cylinder))))
		return (NULL);
	cy->center = center;
	cy->normal = norm;
	cy->diameter = diameter;
	cy->height = h;
	return (cy);
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
