/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:08:18 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/09 16:39:19 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# define _USE_MATH_DEFINES

// 1. 공용 구조�?
typedef struct s_vec3		t_vec3;
typedef struct s_vec3		t_point3;
typedef struct s_vec3		t_color3;
typedef struct s_ray		t_ray;
typedef struct s_hit_record	t_hit_record;

// 2. ?���? 구조�?
typedef struct s_camera		t_camera;
typedef struct s_canvas		t_canvas;
typedef struct s_ambient	t_ambient;
typedef struct s_scene		t_scene;

// 3. ?��브젝?�� 구조�?
typedef struct s_object		t_object;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_triangle	t_triangle;
typedef struct s_cylinder	t_cylinder;
typedef struct s_square		t_square;
typedef struct s_light		t_light;

typedef struct s_img		t_img;
typedef struct s_vars		t_vars;
typedef struct s_mode		t_mode;

typedef struct s_bitmapfileheader	t_bitmapfileheader;
typedef struct s_bitmapinfoheader	t_bitmapinfoheader;
// 4. ?��별자 매크�?
typedef int					t_bool;
# define FALSE 0
# define TRUE 1

// 5. �??�� 구조�? �? 매크�?
# define X 1
# define Y 2
# define Z 3
# define PLUS 4
# define MINUS 5
# define THETA (M_PI / (double)18)

typedef int					t_object_type;
# define SP 1
# define PL 2
# define TR 3
# define CY 4
# define SQ 5
# define CAM 6
# define LIGHT_POINT 7
# define OBJECT 8

# define TRANSLATE 1
# define ROTATE 2
# define SCALE 3
# define OFF 0

// ?���? ?��??? �?
# define EPSILON 1e-6
# define LUMEN 3

// 공용 구조�?
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

// ?���? 구조�?
struct s_camera
{
	t_point3	orig;
	t_vec3		normal;
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

struct	s_ambient
{
	double		ratio;
	t_color3	ambient_color;
};

struct				s_scene
{
	t_canvas		canvas;
	t_object		*camera;
	t_ambient		ambient;
	t_object		*world;
	t_object		*light;
	t_ray			ray;
	t_hit_record	rec;
};

// ?��브젝?�� 구조�?
struct s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
	void			*pre;
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
};

struct s_light
{
	t_point3	origin;
	t_color3	light_color;
	double		bright_ratio;
};

// �??�� 구조�?

struct  s_vars {
		void		*mlx;
		void		*win;
		t_scene		*scene;
		t_img		*img;
		t_mode		*mode;
		t_object	*cur;
		t_bitmapfileheader	*bmp_file;
		t_bitmapinfoheader	*bmp_info;
};

struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct s_mode {
	t_object_type		selected;
	int					trans;
	int					axis;
	int					sign;
};

# pragma pack(push, 1)

struct s_bitmapfileheader     // BMP 비트맵 파일 헤더 구조체
{
    unsigned short bf_type;           // BMP 파일 매직 넘버
    unsigned int   bf_size;           // 파일 크기
    unsigned short bf_reserved1;      // 예약
    unsigned short bf_reserved2;      // 예약
    unsigned int   bf_off_bits;        // 비트맵 데이터의 시작 위치
};

struct s_bitmapinfoheader     // BMP 비트맵 정보 헤더 구조체(DIB 헤더)
{
    unsigned int   bi_size;           // 현재 구조체의 크기
    int            bi_width;          // 비트맵 이미지의 가로 크기
    int            bi_height;         // 비트맵 이미지의 세로 크기
    unsigned short bi_planes;         // 사용하는 색상판의 수
    unsigned short bi_bit_count;       // 픽셀 하나를 표현하는 비트 수
    unsigned int   bi_compression;    // 압축 방식
    unsigned int   bi_size_image;      // 비트맵 이미지의 픽셀 데이터 크기
    int            bi_x_pels_per_meter;  // 그림의 가로 해상도(미터당 픽셀)
    int            bi_y_pels_per_meter;  // 그림의 세로 해상도(미터당 픽셀)
    unsigned int   bi_clr_used;        // 색상 테이블에서 실제 사용되는 색상 수
    unsigned int   bi_clr_important;   // 비트맵을 표현하기 위해 필요한 색상 인덱스 수
};

# pragma pack(pop)

#endif
