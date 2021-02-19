/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:37:27 by hyunlee           #+#    #+#             */
/*   Updated: 2021/02/11 15:07:14 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/utils.h"
#include "../../../include/trace.h"

t_bool	hit_cylinder(t_object *cy_obj, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;
	t_point3	h;			//실린더 꼭대기 점
	t_vec3		h_unit;		//법선 단위벡터
	t_vec3		co;			//실린더 center -> ray_orig 방향 벡터
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		root;
	double		sqrtd;
	t_point3	p;			//교점
	double		h_range;	//실런더 center로부터 실린더 교점 p의 높이

	cy = cy_obj->element;
	h_unit = vunit(cy->normal);
	h = vsum(cy->center, vmul(h_unit, cy->height));
	co = vsub(ray->orig, cy->center);
	// a = (ray_dir * ray_dir) - (ray_dir * h_unit)^2
	a = vdot(ray->dir, ray->dir) - pow(vdot(ray->dir, h_unit), 2);
	// b = 2 * [(ray_dir * co) - (ray_dir * h_unit)(co * h_unit)]
	half_b = vdot(ray->dir, co) - vdot(ray->dir, h_unit) * vdot(co, h_unit);
	// c = (co * co) - (co * h_unit)^2 - radius^2
	c = vdot(co, co) - pow(vdot(co, h_unit), 2) - cy->radius2;
	discriminant = pow(half_b, 2) - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	/*
		작은 값 먼저 확인.
		작은값 법위 내에 없으면, 큰값 범위 확인.
		실런더 높이 안에 근이 존재하는지 확인.
	*/
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
			// 작은 근이 t 범위 안에는 들어가지만, 원기둥 높이 범위에 들어가지 않는 경우
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
