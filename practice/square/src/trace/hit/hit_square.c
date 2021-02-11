/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:45:30 by hyunlee           #+#    #+#             */
/*   Updated: 2021/02/10 14:54:40 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/utils.h"
#include "../../../include/trace.h"

t_bool	hit_square(t_object *sq_obj, t_ray *ray, t_hit_record *rec)
{
	t_square	*sq;
	double		root;
	t_point3	p;
	t_point3	left_bottom;
	t_point3	right_top;
	t_point3	lb;
	t_point3	rt;

	sq = sq_obj->element;
	if (fabs(vdot(sq->normal, ray->dir)) <= EPSILON)
		return (FALSE);
	root = vdot(vsub(sq->center, ray->orig), sq->normal) / vdot(ray->dir, sq->normal);
	if (root < rec->tmin || root > rec->tmax)
		return (FALSE);
	p = ray_at(ray, root);
	left_bottom = vsub(sq->center, vmul(sq->vertex, sq->length / 2));
	right_top = vsum(sq->center, vmul(sq->vertex, sq->length / 2));
	lb.x = left_bottom.x - EPSILON;
	lb.y = left_bottom.y - EPSILON;
	lb.z = left_bottom.z - EPSILON;
	rt.x = right_top.x + EPSILON;
	rt.y = right_top.y + EPSILON;
	rt.z = right_top.z + EPSILON;
	if (p.x < lb.x || p.y < lb.y || p.z < lb.z)
		return (FALSE);
	else if (p.x > rt.x || p.y > rt.y || p.z > rt.z)
		return (FALSE);
	rec->t = root;
	rec->p = p;
	rec->normal = sq->normal;
	set_face_normal(ray, rec);
	rec->albedo = sq_obj->albedo;
	return (TRUE);
}
