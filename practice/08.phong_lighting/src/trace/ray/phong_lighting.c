/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:15:53 by hyunlee           #+#    #+#             */
/*   Updated: 2021/01/26 22:50:17 by hyunlee          ###   ########.fr       */
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
	(ambient + diffuse + specular) * objectColor * 감쇠율;
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
