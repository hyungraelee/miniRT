/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:05:31 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/05 16:13:11 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANS_H
# define TRANS_H

void	translate(t_object *obj, int axis, int sign);
t_point3	translate_center(t_point3 center, int axis, int sign);
void	scale(t_object *obj, int sign);
void	rotate(t_object *obj, int axis, int sign);

#endif
