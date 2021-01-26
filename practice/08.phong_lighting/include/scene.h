/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 13:01:38 by hyunlee           #+#    #+#             */
/*   Updated: 2021/01/26 14:47:49 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "utils.h"

t_canvas	canvas(int	width, int height);
t_camera	camera(t_canvas *canvas, t_point3 orig);
t_object	*object(t_object_type type, void *element);
t_sphere	*sphere(t_point3 center, double radius);
t_light		*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio);

#endif
