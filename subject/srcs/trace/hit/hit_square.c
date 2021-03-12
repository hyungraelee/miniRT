/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:45:30 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 15:19:54 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	make_own_coordinate(t_square *sq)
{
	if (sq->normal.x == 0 && sq->normal.y == 1 && sq->normal.z == 0)
		sq->n_x = vunit(vcross(sq->normal, vec3(1, 0, 0)));
	else
		sq->n_x = vunit(vcross(sq->normal, vec3(0, 1, 0)));
	sq->n_y = vunit(vcross(sq->n_x, sq->normal));
}

t_bool		hit_square(t_object *sq_obj, t_ray *ray, t_hit_record *rec)
{
	t_square	*sq;

	sq = sq_obj->element;
	if (fabs(vdot(sq->normal, ray->dir)) <= EPSILON)
		return (FALSE);
	sq->root = vdot(vsub(sq->center, ray->orig), sq->normal) / \
	vdot(ray->dir, sq->normal);
	if (sq->root < rec->tmin || sq->root > rec->tmax)
		return (FALSE);
	sq->p = ray_at(ray, sq->root);
	make_own_coordinate(sq);
	sq->cp = vsub(sq->p, sq->center);
	if (fabs(vdot(sq->cp, sq->n_x)) > sq->length / 2)
		return (FALSE);
	if (fabs(vdot(sq->cp, sq->n_y)) > sq->length / 2)
		return (FALSE);
	rec->t = sq->root;
	rec->p = sq->p;
	rec->normal = sq->normal;
	set_face_normal(ray, rec);
	rec->albedo = sq_obj->albedo;
	return (TRUE);
}
