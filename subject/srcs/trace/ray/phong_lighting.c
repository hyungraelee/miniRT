/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:15:53 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 15:21:29 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	return (vsub(v, vmul(n, (vdot(v, n) * 2))));
}

static t_bool	in_shadow(t_object *objs, t_ray light_ray, double light_len)
{
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = light_len;
	if (hit(objs, &light_ray, &rec))
		return (TRUE);
	return (FALSE);
}

static t_color3	point_light_get(t_scene *scene, t_light *light)
{
	t_phong		ph;

	ph.light_dir = vsub(light->origin, scene->rec.p);
	ph.light_len = vsize(ph.light_dir);
	ph.light_ray = ray(vsum(scene->rec.p, \
	vmul(scene->rec.normal, EPSILON)), ph.light_dir);
	if (in_shadow(scene->world, ph.light_ray, ph.light_len))
		return (color3(0, 0, 0));
	ph.light_dir = vunit(ph.light_dir);
	ph.view_dir = vunit(vmul(scene->ray.dir, -1));
	ph.reflect_dir = reflect(vmul(ph.light_dir, -1), scene->rec.normal);
	ph.kd = fmax(vdot(scene->rec.normal, ph.light_dir), 0.0);
	ph.ks = 0.5;
	ph.ksn = 64;
	ph.ambient = vmul(scene->ambient.ambient_color, scene->ambient.ratio);
	ph.diffuse = vmul(light->light_color, ph.kd);
	ph.spec = pow(fmax(vdot(ph.view_dir, ph.reflect_dir), 0.0), ph.ksn);
	ph.specular = vmul(vmul(light->light_color, ph.ks), ph.spec);
	ph.brightness = light->bright_ratio * LUMEN;
	return (vmul(vsum(vsum(ph.ambient, ph.diffuse), \
	ph.specular), ph.brightness));
}

t_color3		phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_object	*lights;

	light_color = color3(0, 0, 0);
	lights = scene->light;
	while (lights)
	{
		if (lights->type == LIGHT_POINT)
			light_color = vsum(light_color, \
			point_light_get(scene, lights->element));
		lights = lights->next;
	}
	return (vmin(vmulv(light_color, scene->rec.albedo), color3(1, 1, 1)));
}
