/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:01:21 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 14:31:42 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	get_discriminant(t_sphere *sp, t_ray *ray)
{
	sp->radius = sp->diameter / 2;
	sp->radius2 = pow(sp->radius, 2);
	sp->oc = vsub(ray->orig, sp->center);
	sp->a = vdot(ray->dir, ray->dir);
	sp->half_b = vdot(sp->oc, ray->dir);
	sp->c = vdot(sp->oc, sp->oc) - sp->radius2;
	sp->discriminant = sp->half_b * sp->half_b - sp->a * sp->c;
}

t_bool		hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec)
{
	t_sphere	*sp;

	sp = sp_obj->element;
	get_discriminant(sp, ray);
	if (sp->discriminant < 0)
		return (FALSE);
	sp->sqrtd = sqrt(sp->discriminant);
	sp->root = (-sp->half_b - sp->sqrtd) / sp->a;
	if (sp->root < rec->tmin || rec->tmax < sp->root)
	{
		sp->root = (-sp->half_b + sp->sqrtd) / sp->a;
		if (sp->root < rec->tmin || rec->tmax < sp->root)
			return (FALSE);
	}
	rec->t = sp->root;
	rec->p = ray_at(ray, sp->root);
	rec->normal = vdiv(vsub(rec->p, sp->center), sp->radius);
	set_face_normal(ray, rec);
	rec->albedo = sp_obj->albedo;
	return (TRUE);
}
