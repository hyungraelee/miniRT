/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 23:26:07 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/08 16:19:50 by hyunlee          ###   ########.fr       */
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
	camera->left_bottom = vsum(vsub(vsub(camera->orig, vdiv(camera->horizontal, 2)), vdiv(camera->vertical, 2)), vunit(camera->normal));
}

t_camera	*camera(t_canvas *canvas, t_point3 orig, t_vec3 normal, double degrees)
{
	t_camera	*cam;
	// double		focal_len;
	double		viewport_width;
	double		fov;
	// t_vec3		n_x;
	// t_vec3		n_y;

	cam = (t_camera *)malloc(sizeof(t_camera));
	fov = (M_PI / 180) * degrees;
	viewport_width = 2.0 * tan(fov / 2);
	// focal_len = 1.0;
	cam->orig = orig;
	cam->normal = normal;
	cam->viewport_w = viewport_width;
	cam->viewport_h = viewport_width / canvas->aspect_ratio;
	cam->focal_len = 1.0;
	make_viewport(cam);
	// if (normal.x == 0 && normal.y == 1 && normal.z == 0)
	// 	n_x = vunit(vcross(vec3(1, 0, 0), normal));
	// else
	// 	n_x = vunit(vcross(vec3(0, 1, 0), normal));
	// n_y = vunit(vcross(normal, n_x));
	// cam->horizontal = vmul(n_x, cam->viewport_w);
	// cam->vertical = vmul(n_y, cam->viewport_h);
	// cam->left_bottom = vsum(vsub(vsub(cam->orig, vdiv(cam->horizontal, 2)), vdiv(cam->vertical, 2)), vunit(normal));
	return (cam);
}
