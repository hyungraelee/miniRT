/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:34:28 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/03 15:41:07 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// set Ray
t_ray	ray(t_point3 orig, t_vec3 dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = vunit(dir);
	return (ray);
}

// set primaryRay
t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;

	ray.orig = cam->orig;
	ray.dir = vunit(vsub(vsum(vsum(cam->left_bottom, vmul(cam->horizontal, u)), vmul(cam->vertical, v)), cam->orig));
	return (ray);
}

t_point3	ray_at(t_ray *ray, double t)
{
	t_point3 at;

	at = vsum(ray->orig, vmul(ray->dir, t));
	return (at);
}

t_hit_record	record_init(void)
{
	t_hit_record	record;

	record.tmin = EPSILON;
	// double에서 근사치를 사용하기 때문에 약간의 보정이 필요해서?
	// '버림'을 해버리기 떄문에 한 점에서 second ray를 쏠 때 점 내부에서 밖으로 못나올 수 있음.
	record.tmax = INFINITY;
	return (record);
}

t_color3	ray_color(t_scene *scene)
{
	double			t;

	scene->rec = record_init();
	if (hit(scene->world, &scene->ray, &scene->rec))
		return (phong_lighting(scene));
	else
	{
		t = 0.5 * (scene->ray.dir.y + 1.0);
		return (vsum(vmul(color3(1, 1, 1), 1.0 - t),vmul(color3(0.5, 0.7, 1.0), t)));
	}
}
