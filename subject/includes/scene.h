/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:32:54 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 16:15:51 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

t_canvas	canvas(int	width, int height);
t_camera	*camera(t_canvas *canvas, t_point3 ori, t_vec3 norm, double degree);
void		make_viewport(t_camera *camera);
t_ambient	ambient(double ratio, t_color3 color);
t_object	*object(t_object_type type, void *element, t_color3 albedo);
t_sphere	*sphere(t_point3 center, double diameter);
t_plane		*plane(t_point3 center, t_vec3 normal);
t_square	*square(t_point3 center, t_vec3 normal, double length);
t_cylinder	*cylinder(t_point3 center, t_vec3 norm, double diameter, double h);
t_triangle	*triangle(t_point3 a, t_point3 b, t_point3 c);
t_light		*light_point(t_point3 orig, t_color3 color, double bright_ratio);

#endif
