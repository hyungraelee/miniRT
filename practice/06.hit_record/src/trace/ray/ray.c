/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:34:28 by hyunlee           #+#    #+#             */
/*   Updated: 2021/01/20 16:48:57 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/trace.h"

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

t_color3	ray_color(t_ray	*ray, t_sphere *sphere)
{
	double			t;
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = INFINITY;
	// 광선이 구에 적중하면(광선과 구가 교점이 있고, 교점이 카메라 앞쪽이라면)
	if (hit_sphere(sphere, ray, &rec))
	{
		return (vmul(vsum(rec.normal, color3(1, 1, 1)), 0.5));
	}
	else
	{
		t = 0.5 * (ray->dir.y + 1.0);
		return (vsum(vmul(color3(1, 1, 1), 1.0 - t),vmul(color3(0.5, 0.7, 1.0), t)));
	}
}
