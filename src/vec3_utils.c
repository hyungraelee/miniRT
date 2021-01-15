/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:07:23 by hyunlee           #+#    #+#             */
/*   Updated: 2021/01/15 15:30:56 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct	s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;

t_vec3	ft_create_vector(double a, double b, double c)
{
	t_vec3	vec;

	vec.x = a;
	vec.y = b;
	vec.z = c;
	return (vec);
}

t_vec3	ft_vec_sum(t_vec3 a, t_vec3 b)
{
	t_vec3 v;

	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return (v);
}

t_vec3	ft_vec_sub(t_vec3 a, t_vec3 b)
{
	t_vec3 v;

	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	return (v);
}

t_vec3	ft_vec_mul(t_vec3 a, int t)
{
	t_vec3 v;

	v.x = a.x * t;
	v.y = a.y * t;
	v.z = a.z * t;
	return (v);
}

t_vec3	ft_vec_div(t_vec3 a, int t)
{
	t_vec3 v;

	v.x = a.x / t;
	v.y = a.y / t;
	v.z = a.z / t;
	return (v);
}

double	ft_vec_dot(t_vec3 a, t_vec3 b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_vec3	ft_vec_cross(t_vec3 a, t_vec3 b)
{
	t_vec3 v;

	v.x = (a.y * b.z) - (a.z * b.y);
	v.y = (a.z * b.x) - (a.x * b.z);
	v.z = (a.x * b.y) - (a.y * b.x);
	return (v);
}

// double	ft_vec_size(t_vec3 a)
// {
// 	return ((a.x) * (a.x))
// }

// t_vec3	ft_vec_unit(t_vec3 a)
// {
// 	t_vec3 v;

// }

int	main()
{
	t_vec3	a;
	t_vec3	b;
	t_vec3	c;

	a = ft_create_vector(1.0, 0.0, 0.0);
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

	return (0);
}
