/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:19:22 by hyunlee           #+#    #+#             */
/*   Updated: 2021/02/03 15:14:34 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/utils.h"
#include "../../../include/trace.h"

double	hit_plane(t_object *pl_obj, t_ray *ray, t_hit_record *rec)
{
	t_plane	*pl;
	double	root;

	pl = pl_obj->element;
	if (fabs(vdot(pl->normal, ray->dir)) <= EPSILON)
		return (FALSE);
	root = vdot(vsub(pl->center, ray->orig), pl->normal) /vdot	(ray->dir, pl->normal);
	if (root < rec->tmin || root > rec->tmax)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vunit(pl->normal);
	set_face_normal(ray, rec);
	rec->albedo = pl_obj->albedo;
	return (TRUE);

}
