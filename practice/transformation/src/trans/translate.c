/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 17:10:06 by hyunlee           #+#    #+#             */
/*   Updated: 2021/02/20 16:13:17 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/trans.h"

void	translate_sp(t_object *obj, int axis, int sign)
{
	t_sphere *sp;

	sp = obj->element;
	if (sign == PLUS)
	{
		if (axis == X)
			sp->center.x++;
		else if (axis == Y)
			sp->center.y++;
		else if (axis == Z)
			sp->center.z++;
	}
	else if (sign == MINUS)
	{
		if (axis == X)
			sp->center.x--;
		else if (axis == Y)
			sp->center.y--;
		else if (axis == Z)
			sp->center.z--;
	}
}

void	translate_pl(t_object *obj, int axis, int sign)
{
	t_plane *pl;

	pl = obj->element;
	if (sign == PLUS)
	{
		if (axis == X)
			pl->center.x++;
		else if (axis == Y)
			pl->center.y++;
		else if (axis == Z)
			pl->center.z++;
	}
	else if (sign == MINUS)
	{
		if (axis == X)
			pl->center.x--;
		else if (axis == Y)
			pl->center.y--;
		else if (axis == Z)
			pl->center.z--;
	}
}

void	translate_cy(t_object *obj, int axis, int sign)
{
	t_cylinder *cy;

	cy = obj->element;
	if (sign == PLUS)
	{
		if (axis == X)
			cy->center.x++;
		else if (axis == Y)
			cy->center.y++;
		else if (axis == Z)
			cy->center.z++;
	}
	else if (sign == MINUS)
	{
		if (axis == X)
			cy->center.x--;
		else if (axis == Y)
			cy->center.y--;
		else if (axis == Z)
			cy->center.z--;
	}
}

void	translate_sq(t_object *obj, int axis, int sign)
{
	t_square *sq;

	sq = obj->element;
	if (sign == PLUS)
	{
		if (axis == X)
			sq->center.x++;
		else if (axis == Y)
			sq->center.y++;
		else if (axis == Z)
			sq->center.z++;
	}
	else if (sign == MINUS)
	{
		if (axis == X)
			sq->center.x--;
		else if (axis == Y)
			sq->center.y--;
		else if (axis == Z)
			sq->center.z--;
	}
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
	if (obj->type == SP)
		translate_sp(obj, axis, sign);
	else if (obj->type == PL)
		translate_pl(obj, axis, sign);
	else if (obj->type == TR)
		translate_tr(obj, axis, sign);
	else if (obj->type == CY)
		translate_cy(obj, axis, sign);
	else if (obj->type == SQ)
		translate_sq(obj, axis, sign);
}
