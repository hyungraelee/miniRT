/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:15:43 by hyunlee           #+#    #+#             */
/*   Updated: 2021/02/04 18:00:52 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

// 1. 공용 구조체
typedef struct s_vec3		t_vec3;
typedef struct s_vec3		t_point3;
typedef struct s_vec3		t_color3;
typedef struct s_ray		t_ray;
typedef struct s_hit_record	t_hit_record;

// 2. 장면 구조체
typedef struct s_camera		t_camera;
typedef struct s_canvas		t_canvas;
typedef struct s_scene		t_scene;

// 3. 오브젝트 구조체
typedef struct s_object		t_object;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_triangle	t_triangle;
typedef struct s_cylinder	t_cylinder;
typedef struct s_light		t_light;

// 4. 식별자 매크로
typedef int					t_bool;
# define FALSE 0
# define TRUE 1

typedef int					t_object_type;
# define SP 0
# define LIGHT_POINT 1
# define PL 2
# define TR 3
# define CY 4

// 엄청 작은 값
# define EPSILON 1e-6
# define LUMEN 3

// 공용 구조체
struct	s_vec3
{
	double	x;
	double	y;
	double	z;
};

struct s_ray
{
	t_point3	orig;
	t_vec3		dir;
};

struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	t_bool		front_face;
	double		tmin;
	double		tmax;
	double		t;
	t_color3	albedo;
};

// 장면 구조체
struct s_camera
{
	t_point3	orig;
	double		viewport_w;
	double		viewport_h;
	t_vec3		horizontal;
	t_vec3		vertical;
	double		focal_len;
	t_point3	left_bottom;
};

struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
};

struct				s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_object		*world;
	t_object		*light;
	t_ray			ray;
	t_hit_record	rec;
};

// 오브젝트 구조체
struct s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
	t_color3		albedo;
};

struct s_sphere
{
	t_point3	center;
	double		radius;
	double		radius2;
};

struct s_plane
{
	t_point3	center;
	t_vec3		normal;
};

struct s_triangle
{
	t_point3	a;
	t_point3	b;
	t_point3	c;
	t_vec3		normal;
};

struct s_cylinder
{
	t_point3	center;
	t_vec3		normal;
	double		diameter;
	double		radius;
	double		radius2;
	double		height;
};


struct s_light
{
	t_point3	origin;
	t_color3	light_color;
	double		bright_ratio;
};

#endif
