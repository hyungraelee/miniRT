/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 23:26:07 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 16:27:44 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		make_viewport(t_camera *camera)
{
	t_vec3		n_x;
	t_vec3		n_y;

	if (camera->normal.x == 0 && camera->normal.y == 1 && camera->normal.z == 0)
		n_x = vunit(vcross(vec3(1, 0, 0), camera->normal));
	else
		n_x = vunit(vcross(vec3(0, 1, 0), camera->normal));
	n_y = vunit(vcross(camera->normal, n_x));
	camera->horizontal = vmul(n_x, camera->viewport_w);
	camera->vertical = vmul(n_y, camera->viewport_h);
	camera->left_bottom = vsum(vsub(vsub(camera->orig, \
	vdiv(camera->horizontal, 2)), vdiv(camera->vertical, 2)), \
	vunit(camera->normal));
}

t_camera	*camera(t_canvas *canvas, t_point3 ori, t_vec3 norm, double degree)
{
	t_camera	*cam;
	double		viewport_width;
	double		fov;

	cam = (t_camera *)malloc(sizeof(t_camera));
	fov = (M_PI / 180) * degree;
	viewport_width = 2.0 * tan(fov / 2);
	cam->orig = ori;
	cam->normal = norm;
	cam->viewport_w = viewport_width;
	cam->viewport_h = viewport_width / canvas->aspect_ratio;
	cam->focal_len = 1.0;
	make_viewport(cam);
	return (cam);
}
