/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:34:45 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 15:03:52 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

t_ray		ray(t_point3 orig, t_vec3 dir);
t_ray		ray_primary(t_camera *cam, double u, double v);
t_point3	ray_at(t_ray *ray, double t);
t_color3	ray_color(t_scene *scene);
t_color3	phong_lighting(t_scene *scene);

t_bool		hit(t_object *world, t_ray *ray, t_hit_record *rec);
t_bool		hit_obj(t_object *world, t_ray *ray, t_hit_record *rec);
t_bool		hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec);
t_bool		hit_plane(t_object *pl_obj, t_ray *ray, t_hit_record *rec);
t_bool		hit_triangle(t_object *tr_obj, t_ray *ray, t_hit_record *rec);
t_bool		hit_cylinder(t_object *cy_obj, t_ray *ray, t_hit_record *rec);
t_bool		hit_square(t_object *sq_obj, t_ray *ray, t_hit_record *rec);
void		set_face_normal(t_ray *r, t_hit_record *rec);

#endif
