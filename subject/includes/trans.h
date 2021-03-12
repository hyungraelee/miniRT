/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:05:31 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 15:50:39 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANS_H
# define TRANS_H

void	translate(t_object *obj, int axis, int sign);
void	scale(t_object *obj, int sign);
void	rotate(t_object *obj, int axis, int sign);

void	translate_tr_plus(t_triangle *tr, int axis);
void	translate_tr_minus(t_triangle *tr, int axis);
#endif
