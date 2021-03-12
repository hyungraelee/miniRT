/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:16:43 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 16:10:04 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

t_vec3		vec3(double a, double b, double c);
t_point3	point3(double a, double b, double c);
t_color3	color3(double a, double b, double c);
void		vset(t_vec3 *vec, double a, double b, double c);
t_vec3		vsum(t_vec3 a, t_vec3 b);
t_vec3		vsum2(t_vec3 vec, double a, double b, double c);
t_vec3		vsub(t_vec3 a, t_vec3 b);
t_vec3		vsub2(t_vec3 vec, double a, double b, double c);
t_vec3		vmul(t_vec3 a, double t);
t_vec3		vmulv(t_vec3 a, t_vec3 b);
t_vec3		vdiv(t_vec3 a, double t);
double		vdot(t_vec3 a, t_vec3 b);
t_vec3		vcross(t_vec3 a, t_vec3 b);
double		vsize(t_vec3 a);
t_vec3		vunit(t_vec3 a);
t_vec3		vmin(t_vec3 a, t_vec3 b);

void		oadd(t_object **list, t_object *new);

int			check_input_file(char *argv);

#endif
