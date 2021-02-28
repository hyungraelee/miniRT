/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:23:36 by hyunlee           #+#    #+#             */
/*   Updated: 2021/01/20 15:21:17 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/scene.h"

t_camera	camera(t_canvas *canvas, t_point3 orig)
{
	t_camera	cam;
	double		focal_len;
	double		viewport_height;

	viewport_height = 2.0;
	focal_len = 1.0;
	cam.orig = orig;
	cam.viewport_h = viewport_height;
	cam.viewport_w = viewport_height * canvas->aspect_ratio;
	cam.focal_len = focal_len;
	cam.horizontal = vec3(cam.viewport_w, 0, 0);
	cam.vertical = vec3(0, cam.viewport_h, 0);
	// left_bottom coordinates, origin - (horiaontal / 2) - (vertical / 2) - vec3(0, 0, focal_length)
	cam.left_bottom = vsub(vsub(vsub(cam.orig, vdiv(cam.horizontal, 2)), vdiv(cam.vertical, 2)), vec3(0, 0, focal_len));

	return (cam);
}
