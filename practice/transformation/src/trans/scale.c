/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:07:34 by hyunlee           #+#    #+#             */
/*   Updated: 2021/02/20 16:43:37 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/trans.h"

void	scale_sp(t_object *obj, int sign)
{
	t_sphere	*sp;

	sp = obj->element;
	if (sign == PLUS)
		sp->diameter++;
	else if (sign == MINUS)
		sp->diameter--;
}

// void	scale_pl(t_object *obj, int sign)
// {
// 	t_	*sp;

// 	sp = obj->element;
// 	if (sign == PLUS)
// 		sp->radius++;
// 	else if (sign == MINUS)
// 		sp->radius--;
// }

void	scale_cy(t_object *obj, int sign)
{
	t_cylinder	*cy;
	double		aspect_ratio;

	cy = obj->element;
	aspect_ratio = cy->diameter / cy->height;
	if (sign == PLUS)
		cy->diameter++;
	else if (sign == MINUS)
		cy->diameter--;
	cy->height = cy->diameter / aspect_ratio;
}

void	scale_sq(t_object *obj, int sign)
{
	t_square	*sq;

	sq = obj->element;
	if (sign == PLUS)
		sq->length++;
	else if (sign == MINUS)
		sq->length--;
}

void	scale(t_object *obj, int sign)
{
	if (obj->type == SP)
		scale_sp(obj, sign);
	// else if (obj->type == PL)
	// 	scale_pl(obj, sign);
	// else if (obj->type == TR)
	// 	scale_tr(obj, sign);
	else if (obj->type == CY)
		scale_cy(obj, sign);
	else if (obj->type == SQ)
		scale_sq(obj, sign);
}
