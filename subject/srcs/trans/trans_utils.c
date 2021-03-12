/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:45:10 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 15:49:54 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	translate_tr_plus(t_triangle *tr, int axis)
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

void	translate_tr_minus(t_triangle *tr, int axis)
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
