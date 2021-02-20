/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:01:21 by hyunlee           #+#    #+#             */
/*   Updated: 2021/02/20 16:37:38 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/utils.h"
#include "../../../include/trace.h"


//hit_sphere의 첫반째 인자를 (t_sphere *) 에서 (t_object *)로 바꿔준 이유는
//이후 텍스쳐, 회전변환등을 t_object 구조체에 추가할 것이기 때문에 미리 수정해둔 것.

t_bool	hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec)
{
	t_sphere	*sp;
	t_vec3		oc;
	double		a;
	double		half_b;
	double		c;
	double		discriminant; //판별식
	double		sqrtd;
	double		root;

	sp = sp_obj->element;
	sp->radius = sp->diameter / 2;
	sp->radius2 = pow(sp->radius, 2);
	oc = vsub(ray->orig, sp->center);
	a = vdot(ray->dir, ray->dir);
	half_b = vdot(oc, ray->dir);
	c = vdot(oc, oc) - sp->radius2;
	discriminant = half_b * half_b - a * c;

	if (discriminant < 0) //실근이 없을 때
		return (FALSE);

	// 두 실근(t) 중 tmin과 tmax 사이에 있는 근이 있는지 체크, 작은 근부터 체크.
	sqrtd = sqrt(discriminant); // 짝수 판별식 제곱근
	root = (-half_b - sqrtd) / a; // 짝수 근의공식 (작은 근)
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a; // 짝수 근의공식 (큰 근)
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vdiv(vsub(rec->p, sp->center), sp->radius); // 정규화된 법선 벡터
	set_face_normal(ray, rec); // rec의 법선벡터와 광선의 방향벡터를 비교해서 앞면인지 뒷면인지 t_bool 값으로 저장.
	rec->albedo = sp_obj->albedo;
	return (TRUE);
}
