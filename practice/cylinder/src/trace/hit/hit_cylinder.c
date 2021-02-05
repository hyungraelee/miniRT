/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:37:27 by hyunlee           #+#    #+#             */
/*   Updated: 2021/02/05 18:10:44 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/utils.h"
#include "../../../include/trace.h"

t_bool	hit_cylinder(t_object *cy_obj, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;
	t_point3	h;
	t_vec3		h_unit;
	t_vec3		co;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		root;
	double		sqrtd;
	t_point3	p;
	double		h_range;

	cy = cy_obj->element;
	h_unit = vunit(cy->normal);
	h = vsum(cy->center, vmul(h_unit, cy->height));
	co = vsub(ray->orig, cy->center);
	a = vdot(ray->dir, ray->dir) - pow(vdot(ray->dir, h_unit), 2);
	half_b = vdot(ray->dir, co) - vdot(ray->dir, h_unit) * vdot(co, h_unit);
	c = vdot(co, co) - pow(vdot(co, h_unit), 2) - cy->radius2;
	discriminant = pow(half_b, 2) - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
		p = ray_at(ray, root);
		h_range = vdot(vsub(p, cy->center), h_unit);
		if (h_range < 0 || h_range > cy->height)
			return (FALSE);
	}
	else
	{
		p = ray_at(ray, root);
		h_range = vdot(vsub(p, cy->center), h_unit);
		if (h_range < 0 || h_range > cy->height)
		{
			root = (-half_b + sqrtd) / a;
			if (root < rec->tmin || rec->tmax < root)
				return (FALSE);
			p = ray_at(ray, root);
			h_range = vdot(vsub(p, cy->center), h_unit);
			if (h_range < 0 || h_range > cy->height)
				return (FALSE);
		}
	}
	rec->t = root;
	rec->p = p;
	rec->normal = vdiv(vsub(p, vsum(cy->center, vmul(h_unit, h_range))), cy->radius);
	set_face_normal(ray, rec);
	rec->albedo = cy_obj->albedo;
	return (TRUE);
}
