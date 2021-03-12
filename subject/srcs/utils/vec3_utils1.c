/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:04:32 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 16:07:55 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3		vsum(t_vec3 a, t_vec3 b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_vec3		vsum2(t_vec3 vec, double a, double b, double c)
{
	vec.x += a;
	vec.y += b;
	vec.z += c;
	return (vec);
}

t_vec3		vsub(t_vec3 a, t_vec3 b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_vec3		vsub2(t_vec3 vec, double a, double b, double c)
{
	vec.x -= a;
	vec.y -= b;
	vec.z -= c;
	return (vec);
}
