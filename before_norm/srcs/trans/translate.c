/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 17:10:06 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 12:53:25 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point3	translate_center(t_point3 center, int axis, int sign)
{
	if (sign == PLUS)
	{
		if (axis == X)
			center.x++;
		else if (axis == Y)
			center.y++;
		else if (axis == Z)
			center.z++;
	}
	else if (sign == MINUS)
	{
		if (axis == X)
			center.x--;
		else if (axis == Y)
			center.y--;
		else if (axis == Z)
			center.z--;
	}
	return (center);
}

void	translate_tr(t_object *obj, int axis, int sign)
{
	t_triangle *tr;

	tr = obj->element;
	if (sign == PLUS)
	{
		if (axis == X)
		{
			tr->a.x++;
			tr->b.x++;
			tr->c.x++;
		}
		else if (axis == Y)
		{
			tr->a.y++;
			tr->b.y++;
			tr->c.y++;
		}
		else if (axis == Z)
		{
			tr->a.z++;
			tr->b.z++;
			tr->c.z++;
		}
	}
	else if (sign == MINUS)
	{
		if (axis == X)
		{
			tr->a.x--;
			tr->b.x--;
			tr->c.x--;
		}
		else if (axis == Y)
		{
			tr->a.y--;
			tr->b.y--;
			tr->c.y--;
		}
		else if (axis == Z)
		{
			tr->a.z--;
			tr->b.z--;
			tr->c.z--;
		}
	}
}

void	translate(t_object *obj, int axis, int sign)
{
	t_sphere	*sp;
	t_plane		*pl;
	t_triangle	*tr;
	t_cylinder	*cy;
	t_square	*sq;
	t_light		*li;
	t_camera	*cam;

	if (obj->type == SP)
	{
		sp = obj->element;
		sp->center = translate_center(sp->center, axis, sign);
	}
	else if (obj->type == PL)
	{
		pl = obj->element;
		pl->center = translate_center(pl->center, axis, sign);
	}
	else if (obj->type == TR)
		translate_tr(obj, axis, sign);
	else if (obj->type == CY)
	{
		cy = obj->element;
		cy->center = translate_center(cy->center, axis, sign);
	}
	else if (obj->type == SQ)
	{
		sq = obj->element;
		sq->center = translate_center(sq->center, axis, sign);
	}
	else if (obj->type == LIGHT_POINT)
	{
		li = obj->element;
		li->origin = translate_center(li->origin, axis, sign);
	}
	else if (obj->type == CAM)
	{
		cam = obj->element;
		cam->orig = translate_center(cam->orig, axis, sign);
	}
}
