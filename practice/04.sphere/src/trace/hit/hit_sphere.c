/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:01:21 by hyunlee           #+#    #+#             */
/*   Updated: 2021/01/19 18:33:35 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/utils.h"

t_bool	hit_sphere(t_sphere *sp, t_ray *ray)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant; //판별식

	oc = vsub(ray->orig, sp->center);
	a = vdot(ray->dir, ray->dir);
	b = 2.0 * vdot(oc, ray->dir);
	c = vdot(oc, oc) - sp->radius2;
	discriminant = b * b - 4 * a * c;
	return (discriminant > 0);
}
