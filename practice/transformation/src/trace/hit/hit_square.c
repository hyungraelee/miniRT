/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:45:30 by hyunlee           #+#    #+#             */
/*   Updated: 2021/02/25 18:26:12 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../../include/utils.h"
#include "../../../include/trace.h"

t_bool	hit_square(t_object *sq_obj, t_ray *ray, t_hit_record *rec)
{
	t_square	*sq;
	double		root;
	t_point3	p;
	// double		a;
	// double		b;
	// double		c;
	double		gradient;
	double		theta;
	t_point3	sq_p1;
	t_point3	sq_p2;

	sq = sq_obj->element;
	if (fabs(vdot(sq->normal, ray->dir)) <= EPSILON)
		return (FALSE);
	// 평면과 ray의 교점
	// t = ((sq->center - ray->orig) * sq->normal) / (ray->dir * sq->normal)
	root = vdot(vsub(sq->center, ray->orig), sq->normal) / vdot(ray->dir, sq->normal);
	if (root < rec->tmin || root > rec->tmax)
		return (FALSE);
	p = ray_at(ray, root);

	/*
	center와 normal이 만드는 평면에서 center의 z좌표와 같은 z값을 갖는 다른 두 점을 구한다.
	z = center.z 인 평면으로 위의 평면을 자른다는 개념.
	그럼
	*/
	gradient = -sq->normal.x / sq->normal.y;
	theta = atan(gradient);
	if (sq->normal.x >= 0)
	{
		if (sq->normal.y > 0)
		{
			sq_p1.x = sq->center.x + cos(theta) * ((sqrt(2) / 2) * sq->length);
			sq_p1.y = sq->center.y - sin(theta) * ((sqrt(2) / 2) * sq->length);
			sq_p1.z = sq->center.z;
			sq_p2.x = sq->center.x - cos(theta) * ((sqrt(2) / 2) * sq->length);
			sq_p2.y = sq->center.y + sin(theta) * ((sqrt(2) / 2) * sq->length);
			sq_p2.z = sq->center.z;
		}
		else
		{
			sq_p1.x = sq->center.x + cos(theta) * ((sqrt(2) / 2) * sq->length);
			sq_p1.y = sq->center.y + sin(theta) * ((sqrt(2) / 2) * sq->length);
			sq_p1.z = sq->center.z;
			sq_p2.x = sq->center.x - cos(theta) * ((sqrt(2) / 2) * sq->length);
			sq_p2.y = sq->center.y - sin(theta) * ((sqrt(2) / 2) * sq->length);
			sq_p2.z = sq->center.z;
		}
	}
	else if (sq->normal.x < 0)
	{
		if (sq->normal.y > 0)
		{
			sq_p1.x = sq->center.x + cos(theta) * ((sqrt(2) / 2) * sq->length);
			sq_p1.y = sq->center.y + sin(theta) * ((sqrt(2) / 2) * sq->length);
			sq_p1.z = sq->center.z;
			sq_p2.x = sq->center.x - cos(theta) * ((sqrt(2) / 2) * sq->length);
			sq_p2.y = sq->center.y - sin(theta) * ((sqrt(2) / 2) * sq->length);
			sq_p2.z = sq->center.z;
		}
		else
		{
			sq_p1.x = sq->center.x + cos(theta) * ((sqrt(2) / 2) * sq->length);
			sq_p1.y = sq->center.y - sin(theta) * ((sqrt(2) / 2) * sq->length);
			sq_p1.z = sq->center.z;
			sq_p2.x = sq->center.x - cos(theta) * ((sqrt(2) / 2) * sq->length);
			sq_p2.y = sq->center.y + sin(theta) * ((sqrt(2) / 2) * sq->length);
			sq_p2.z = sq->center.z;
		}
	}

	if (sq_p1.x > sq_p2.x + EPSILON)
	{
		if (p.x > (sq_p1.x + EPSILON) || p.x < (sq_p2.x - EPSILON))
			return (FALSE);
	}
	else if (sq_p1.x + EPSILON < sq_p2.x)
	{
		if (p.x < (sq_p1.x - EPSILON) || p.x > (sq_p2.x + EPSILON))
			return (FALSE);
	}
	else if (fabs(sq_p1.x - sq_p2.x) > EPSILON)
	{
		if (p.x < (sq_p1.x - EPSILON) || p.x > (sq_p1.x + EPSILON))
			return (FALSE);
	}

	if (sq_p1.y > sq_p2.y + EPSILON)
	{
		if (p.y > (sq_p1.y + EPSILON) || p.y < (sq_p2.y - EPSILON))
			return (FALSE);
	}
	else if (sq_p1.y + EPSILON < sq_p2.y)
	{
		if (p.y < (sq_p1.y - EPSILON) || p.y > (sq_p2.y + EPSILON))
			return (FALSE);
	}
	else if (fabs(sq_p1.y - sq_p2.y) < EPSILON)
	{
		if (p.y < (sq_p1.y - EPSILON) || p.y > (sq_p1.y + EPSILON))
			return (FALSE);
	}

	rec->t = root;
	rec->p = p;
	rec->normal = sq->normal;
	set_face_normal(ray, rec);
	rec->albedo = sq_obj->albedo;
	return (TRUE);
}
