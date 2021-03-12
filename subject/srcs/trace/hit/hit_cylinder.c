/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:37:27 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 15:20:30 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	get_discriminant(t_cylinder *cy, t_ray *ray)
{
	cy->radius = cy->diameter / 2;
	cy->radius2 = pow(cy->radius, 2);
	cy->h_unit = vunit(cy->normal);
	cy->h = vsum(cy->center, vmul(cy->h_unit, cy->height));
	cy->co = vsub(ray->orig, cy->center);
	cy->a = vdot(ray->dir, ray->dir) - pow(vdot(ray->dir, cy->h_unit), 2);
	cy->half_b = vdot(ray->dir, cy->co) - vdot(ray->dir, cy->h_unit) * \
	vdot(cy->co, cy->h_unit);
	cy->c = vdot(cy->co, cy->co) - \
	pow(vdot(cy->co, cy->h_unit), 2) - cy->radius2;
	cy->discriminant = pow(cy->half_b, 2) - cy->a * cy->c;
	cy->sqrtd = sqrt(cy->discriminant);
}

static int	check_big_root(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	cy->root = (-cy->half_b + cy->sqrtd) / cy->a;
	if (cy->root < rec->tmin || rec->tmax < cy->root)
		return (0);
	cy->p = ray_at(ray, cy->root);
	cy->h_range = vdot(vsub(cy->p, cy->center), cy->h_unit);
	if (cy->h_range < 0 || cy->h_range > cy->height)
		return (0);
	return (1);
}

static int	check_small_root(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	cy->p = ray_at(ray, cy->root);
	cy->h_range = vdot(vsub(cy->p, cy->center), cy->h_unit);
	if (cy->h_range < 0 || cy->h_range > cy->height)
	{
		cy->root = (-cy->half_b + cy->sqrtd) / cy->a;
		if (cy->root < rec->tmin || rec->tmax < cy->root)
			return (FALSE);
		cy->p = ray_at(ray, cy->root);
		cy->h_range = vdot(vsub(cy->p, cy->center), cy->h_unit);
		if (cy->h_range < 0 || cy->h_range > cy->height)
			return (FALSE);
	}
	return (1);
}

t_bool		hit_cylinder(t_object *cy_obj, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;

	cy = cy_obj->element;
	get_discriminant(cy, ray);
	if (cy->discriminant < 0)
		return (FALSE);
	cy->root = (-cy->half_b - cy->sqrtd) / cy->a;
	if (cy->root < rec->tmin || rec->tmax < cy->root)
	{
		if (!(check_big_root(cy, ray, rec)))
			return (FALSE);
	}
	else
	{
		if (!(check_small_root(cy, ray, rec)))
			return (FALSE);
	}
	rec->t = cy->root;
	rec->p = cy->p;
	rec->normal = vdiv(vsub(cy->p, vsum(cy->center, \
	vmul(cy->h_unit, cy->h_range))), cy->radius);
	set_face_normal(ray, rec);
	rec->albedo = cy_obj->albedo;
	return (TRUE);
}
