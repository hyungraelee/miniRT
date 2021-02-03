/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:36:24 by hyunlee           #+#    #+#             */
/*   Updated: 2021/02/03 18:36:01 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/utils.h"
#include "../../../include/trace.h"

t_bool	check_in_out(t_point3 p, t_triangle *tr)
{
	t_vec3		ab;
	t_vec3		bc;
	t_vec3		ca;

	ab = vsub(tr->b, tr->a);
	bc = vsub(tr->c, tr->b);
	ca = vsub(tr->a, tr->c);
	if (vdot(tr->normal, vcross(ab, vsub(p, tr->a))) < 0)
		return (FALSE);
	if (vdot(tr->normal, vcross(bc, vsub(p, tr->b))) < 0)
		return (FALSE);
	if (vdot(tr->normal, vcross(ca, vsub(p, tr->c))) < 0)
		return (FALSE);
	return (TRUE);
}

double	hit_triangle(t_object *tr_obj, t_ray *ray, t_hit_record *rec)
{
	t_triangle	*tr;
	double		d;
	double		root;
	t_point3	p;

	tr = tr_obj->element;
	if (fabs(vdot(tr->normal, ray->dir)) <= EPSILON)
		return (FALSE);
	d = vdot(tr->normal, tr->a) * (-1);
	root = (-1) * (vdot(tr->normal, ray->orig) + d) / vdot(tr->normal, ray->dir);
	if (root < rec->tmin || root > rec->tmax)
		return (FALSE);
	p = ray_at(ray,root);
	if (!(check_in_out(p, tr)))
		return (FALSE);
	rec->t = root;
	rec->p = p;
	rec->normal = vunit(tr->normal);
	set_face_normal(ray, rec);
	rec->albedo = tr_obj->albedo;
	return (TRUE);
}
