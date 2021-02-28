/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:45:36 by hyunlee           #+#    #+#             */
/*   Updated: 2021/02/04 18:04:53 by hyunlee          ###   ########.fr       */
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

	if (!(pl = (t_plane*)malloc(sizeof(t_plane))))
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
