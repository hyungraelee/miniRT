/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:45:30 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/03 15:41:16 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	hit_square(t_object *sq_obj, t_ray *ray, t_hit_record *rec)
{
	t_square	*sq;
	double		root;
	t_point3	p;
	t_vec3		n_x;
	t_vec3		n_y;
	t_vec3		cp;


	sq = sq_obj->element;
	if (fabs(vdot(sq->normal, ray->dir)) <= EPSILON)
		return (FALSE);
	// ?��면과 ray?�� 교점
	// t = ((sq->center - ray->orig) * sq->normal) / (ray->dir * sq->normal)
	root = vdot(vsub(sq->center, ray->orig), sq->normal) / vdot(ray->dir, sq->normal);
	if (root < rec->tmin || root > rec->tmax)
		return (FALSE);
	p = ray_at(ray, root);

	if (sq->normal.x == 0 && sq->normal.y == 1 && sq->normal.z == 0)
		n_x = vunit(vcross(sq->normal, vec3(1, 0, 0)));
	else
		n_x = vunit(vcross(sq->normal, vec3(0, 1, 0)));
	n_y = vunit(vcross(n_x, sq->normal));

	cp = vsub(p, sq->center);
	if (fabs(vdot(cp, n_x)) > sq->length / 2)
		return (FALSE);
	if (fabs(vdot(cp, n_y)) > sq->length / 2)
		return (FALSE);

	rec->t = root;
	rec->p = p;
	rec->normal = sq->normal;
	set_face_normal(ray, rec);
	rec->albedo = sq_obj->albedo;
	return (TRUE);
}
