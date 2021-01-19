/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:34:45 by hyunlee           #+#    #+#             */
/*   Updated: 2021/01/19 12:49:57 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "structures.h"
# include "utils.h"

t_ray	ray(t_point3 orig, t_vec3 dir);
t_ray	ray_primary(t_camera *cam, double u, double v);
t_point3	ray_at(t_ray *ray, double t);
t_color3	ray_color(t_ray	*r);


#endif
