/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:04:27 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 16:07:45 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3		vcross(t_vec3 a, t_vec3 b)
{
	t_vec3 v;

	v.x = (a.y * b.z) - (a.z * b.y);
	v.y = (a.z * b.x) - (a.x * b.z);
	v.z = (a.x * b.y) - (a.y * b.x);
	return (v);
}

double		vsize(t_vec3 a)
{
	return (sqrt(pow(a.x, 2.0) + pow(a.y, 2.0) + pow(a.z, 2.0)));
}

t_vec3		vunit(t_vec3 a)
{
	t_vec3	v;
	double	size;

	size = vsize(a);
	v.x = a.x / size;
	v.y = a.y / size;
	v.z = a.z / size;
	return (v);
}

t_vec3		vmin(t_vec3 a, t_vec3 b)
{
	if (a.x > b.x)
		a.x = b.x;
	if (a.y > b.y)
		a.y = b.y;
	if (a.z > b.z)
		a.z = b.z;
	return (a);
}
