/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:07:23 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 16:07:41 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3		vec3(double a, double b, double c)
{
	t_vec3	v;

	v.x = a;
	v.y = b;
	v.z = c;
	return (v);
}

t_point3	point3(double a, double b, double c)
{
	t_point3	p;

	p.x = a;
	p.y = b;
	p.z = c;
	return (p);
}

t_color3	color3(double a, double b, double c)
{
	t_color3	color;

	color.x = a;
	color.y = b;
	color.z = c;
	return (color);
}

double		vdot(t_vec3 a, t_vec3 b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}
