/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:04:30 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 16:07:19 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3		vmul(t_vec3 a, double t)
{
	t_vec3 v;

	v.x = a.x * t;
	v.y = a.y * t;
	v.z = a.z * t;
	return (v);
}

t_vec3		vmulv(t_vec3 a, t_vec3 b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return (a);
}

void		vset(t_vec3 *vec, double a, double b, double c)
{
	vec->x = a;
	vec->y = b;
	vec->z = c;
}

t_vec3		vdiv(t_vec3 a, double t)
{
	t_vec3 v;

	v.x = a.x / t;
	v.y = a.y / t;
	v.z = a.z / t;
	return (v);
}
