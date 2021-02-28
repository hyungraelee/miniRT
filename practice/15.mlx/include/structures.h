/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:15:43 by hyunlee           #+#    #+#             */
/*   Updated: 2021/02/28 14:21:33 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# define _USE_MATH_DEFINES
# include <math.h>

// 1. Í≥µÏö© Íµ¨Ï°∞Ï≤?
typedef struct s_vec3		t_vec3;
typedef struct s_vec3		t_point3;
typedef struct s_vec3		t_color3;
typedef struct s_ray		t_ray;
typedef struct s_hit_record	t_hit_record;

// 2. ?û•Î©? Íµ¨Ï°∞Ï≤?
typedef struct s_camera		t_camera;
typedef struct s_canvas		t_canvas;
typedef struct s_scene		t_scene;

// 3. ?ò§Î∏åÏ†ù?ä∏ Íµ¨Ï°∞Ï≤?
typedef struct s_object		t_object;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_triangle	t_triangle;
typedef struct s_cylinder	t_cylinder;
typedef struct s_square		t_square;
typedef struct s_light		t_light;

typedef struct s_data		t_data;

// 4. ?ãùÎ≥ÑÏûê Îß§ÌÅ¨Î°?
typedef int					t_bool;
# define FALSE 0
# define TRUE 1

// 5. Î≥??ôò Íµ¨Ï°∞Ï≤? Î∞? Îß§ÌÅ¨Î°?
# define X 1
# define Y 2
# define Z 3
# define PLUS 4
# define MINUS 5
# define THETA (M_PI / (double)18)

typedef int					t_object_type;
# define SP 0
# define LIGHT_POINT 1
# define PL 2
# define TR 3
# define CY 4
# define SQ 5

// ?óÑÏ≤? ?ûë??? Í∞?
# define EPSILON 1e-6
# define LUMEN 3

// Í≥µÏö© Íµ¨Ï°∞Ï≤?
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

// ?û•Î©? Íµ¨Ï°∞Ï≤?
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

// ?ò§Î∏åÏ†ù?ä∏ Íµ¨Ï°∞Ï≤?
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
	double		diameter;
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

struct s_square
{
	t_point3	center;
	t_vec3		normal;
	double		length;
	t_vec3		vertex;
};

struct s_light
{
	t_point3	origin;
	t_color3	light_color;
	double		bright_ratio;
};

// Î≥??ôò Íµ¨Ï°∞Ï≤?



struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

#endif
