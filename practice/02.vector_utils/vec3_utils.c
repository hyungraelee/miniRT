/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:07:23 by hyunlee           #+#    #+#             */
/*   Updated: 2021/01/18 12:51:07 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

t_vec3	vec3(double a, double b, double c)
{
	t_vec3	v;

	v.x = a;
	v.y = b;
	v.z = c;
	return (v);
}

t_point3 point3(double a, double b, double c)
{
	t_point3	p;

	p.x = a;
	p.y = b;
	p.z = c;
	return (p);
}

t_color3 color3(double a, double b, double c)
{
	t_color3	color;

	color.x = a;
	color.y = b;
	color.z = c;
	return (color);
}

void	vset(t_vec3 *vec, double a, double b, double c)
{
	vec->x = a;
	vec->y = b;
	vec->z = c;
}

t_vec3	vsum(t_vec3 a, t_vec3 b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_vec3	vsum2(t_vec3 vec, double a, double b, double c)
{
	vec.x += a;
	vec.y += b;
	vec.z += c;
	return (vec);
}

t_vec3	vsub(t_vec3 a, t_vec3 b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_vec3	vsub2(t_vec3 vec, double a, double b, double c)
{
	vec.x -= a;
	vec.y -= b;
	vec.z -= c;
	return (vec);
}

t_vec3	vmul(t_vec3 a, double t)
{
	t_vec3 v;

	v.x = a.x * t;
	v.y = a.y * t;
	v.z = a.z * t;
	return (v);
}

t_vec3	vdiv(t_vec3 a, double t)
{
	t_vec3 v;

	v.x = a.x / t;
	v.y = a.y / t;
	v.z = a.z / t;
	return (v);
}

double	vdot(t_vec3 a, t_vec3 b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_vec3	vcross(t_vec3 a, t_vec3 b)
{
	t_vec3 v;

	v.x = (a.y * b.z) - (a.z * b.y);
	v.y = (a.z * b.x) - (a.x * b.z);
	v.z = (a.x * b.y) - (a.y * b.x);
	return (v);
}

double	vsize(t_vec3 a)
{
	return (sqrt(pow(a.x, 2.0) + pow(a.y, 2.0) + pow(a.z, 2.0)));
}

t_vec3	vunit(t_vec3 a)
{
	t_vec3	v;
	double	size;

	size = ft_vec_size(a);
	v.x = a.x / size;
	v.y = a.y / size;
	v.z = a.z / size;
	return (v);
}

int	main()
{
	t_vec3	a;
	t_vec3	b;
	t_vec3	c;

	a = ft_create_vector(2.0, 4.0, 3.0);
	b = ft_create_vector(0.0, 0.0, 1.0);
	c = ft_vec_sum(a, b);
	printf("a = %f, %f, %f\n", a.x, a.y, a.z);
	printf("b = %f, %f, %f\n", b.x, b.y, b.z);
	printf("c = %f, %f, %f\n", c.x, c.y, c.z);
	c = ft_vec_sub(a, b);
	printf("c = %f, %f, %f\n", c.x, c.y, c.z);
	c = ft_vec_mul(a, 2);
	printf("c = %f, %f, %f\n", c.x, c.y, c.z);
	c = ft_vec_div(a, 2);
	printf("c = %f, %f, %f\n", c.x, c.y, c.z);
	printf("dot = %f\n", ft_vec_dot(a, b));
	c = ft_vec_cross(a, b);
	printf("c = %f, %f, %f\n", c.x, c.y, c.z);
	c = ft_vec_unit(a);
	printf("c = %f, %f, %f\n", c.x, c.y, c.z);


	return (0);
}
