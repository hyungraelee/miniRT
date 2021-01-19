/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:34:28 by hyunlee           #+#    #+#             */
/*   Updated: 2021/01/19 18:37:05 by hyunlee          ###   ########.fr       */
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
	double t;

	if (hit_sphere(sphere, ray))
		return (color3(0, 0.8, 0.8));
	else
	{
		t = 0.5 * (ray->dir.y + 1.0);
		return (vsum(vmul(color3(1, 1, 1), 1.0 - t),vmul(color3(0.5, 0.7, 1.0), t)));
	}
}
