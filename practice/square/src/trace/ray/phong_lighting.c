/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:15:53 by hyunlee           #+#    #+#             */
/*   Updated: 2021/01/28 11:52:19 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/trace.h"

t_color3	phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_object	*lights;

	light_color = color3(0, 0, 0);
	lights = scene->light;
	while (lights)
	{
		if (lights->type == LIGHT_POINT)
			light_color = vsum(light_color, point_light_get(scene, lights->element));
		lights = lights->next;
	}
	// dprintf(2,"light_color:%f, %f, %f\n", light_color.x, light_color.y, light_color.z);
	return (vmin(vmulv(light_color, scene->rec.albedo), color3(1, 1, 1)));
}

/*
	(ambient + diffuse + specular) * objectColor;
	vec3 lightDir = normalize(lightPos - FragPos);
	>> object에서 광원을 가리키는 방향의 단위벡터

	ambient
		float	ambientStrength = 0.1;
		vec3	ambient = ambientStrength * lightColor;
		vec3	result = ambient * objectColor;

	diffuse
		float	diff = max(vdot(norm, lightDir), 0.0);
		vec3	diffuse = diff * lightColor;
	>> vdot(norm, lightDir) 에서 법선벡터와 lightDir 두 벡터사이의 각이 클수록 어두워진다.
	그리고 각이 90도보다 크면 음수가 되는데, result에 곱해줄 diff값이 음수가 되어버리므로, 내적결과와 0.0중 큰 값을 반환하여 음수가 되지 않도록 한다.

	specular
		vec3	viewDir = normalize(viewPos - FragPos);
				>> 공에서 눈 방향
		vec3	reflectDir = reflect(-lightDir, norm);
				>> 광원 -> 공 -> (법선 기준 입사각=반사각으로 반사)반사광선
		float	spec = pow(max(vdot(viewDir, reflectDir), 0.0), 32);
				>> 32제곱은 highlight의 반짝이는 정도(shininess value)로 반짝이는 정도가 높을수록 하이라이트는 작아진다.
		vec3	specular = specularStrength * spec * lightColor;
		vec3	result = (ambient + diffuse + specular) * objectColor;
*/

t_vec3		reflect(t_vec3 v, t_vec3 n)
{
	// v + (2 * (n * dot(-v, n)))
	return (vsub(v, vmul(n, (vdot(v, n) * 2))));
}

t_bool		in_shadow(t_object *objs, t_ray light_ray, double light_len)
{
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = light_len;
	if (hit(objs, &light_ray, &rec))
		return (TRUE);
	return (FALSE);
}

t_color3	point_light_get(t_scene *scene, t_light *light)
{
	t_color3	ambient;
	t_color3	diffuse;
	t_color3	specular;
	t_vec3		light_dir;
	double		light_len;
	t_ray		light_ray;
	t_vec3		view_dir;
	t_vec3		reflect_dir;

	double		ka;
	double		kd;
	double		ks;
	double		ksn;
	double		spec;
	double		brightness;

	light_dir = vsub(light->origin, scene->rec.p);
	light_len = vsize(light_dir);
	light_ray = ray(vsum(scene->rec.p, vmul(scene->rec.normal, EPSILON)), light_dir); // 여기 이해안감
	if (in_shadow(scene->world, light_ray, light_len))
		return (color3(0, 0, 0));
	light_dir = vunit(light_dir);
	view_dir = vunit(vmul(scene->ray.dir, -1)); // primary ray 거꾸로 뒤집음.
	reflect_dir = reflect(vmul(light_dir, -1), scene->rec.normal);
	ka = 0.1; // ambient strength
	kd = fmax(vdot(scene->rec.normal, light_dir), 0.0); // diffuse strength
	ks = 0.5; // specular strength 이거 우리 과제에서 rt파일에 어떻게 들어오는지 체크
	ksn = 64; // 이거 우리 과제에서 rt파일에 어떻게 들어오는지 체크
	ambient = vmul(light->light_color, ka);
	diffuse = vmul(light->light_color, kd);
	spec = pow(fmax(vdot(view_dir, reflect_dir), 0.0), ksn);
	specular = vmul(vmul(light->light_color, ks), spec);
	brightness = light->bright_ratio * LUMEN; // 기준 광속/광량을 정의한 매크로
	return (vmul(vsum(vsum(ambient, diffuse), specular), brightness));
}
