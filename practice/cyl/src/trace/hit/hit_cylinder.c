/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:37:27 by hyunlee           #+#    #+#             */
/*   Updated: 2021/02/05 15:35:47 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/utils.h"
#include "../../../include/trace.h"

t_bool	hit_cylinder(t_object *cy_obj, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		sqrtd;
	double		root;
	t_point3		axis;

	cy = cy_obj->element;
	a = (ray->dir.x * ray->dir.x) + (ray->dir.z * ray->dir.z);
	half_b = ray->dir.x * (ray->orig.x - cy->center.x) + ray->dir.z * (ray->orig.z - cy->center.z);

	c = (ray->orig.x - cy->center.x) * (ray->orig.x - cy->center.x) + (ray->orig.z - cy->center.z) * (ray->orig.z - cy->center.z) - cy->radius2;
	discriminant = half_b * half_b - a * c;

	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	axis = cy->center;
	axis.y = rec->p.y;
	if (axis.y - cy->center.y > cy->height || axis.y < cy->center.y)
		return (FALSE);
	rec->normal = vdiv(vsub(rec->p, axis), cy->radius);
	set_face_normal(ray, rec);
	rec->albedo = cy_obj->albedo;
	return (TRUE);
}
