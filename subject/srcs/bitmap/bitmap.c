/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:52:55 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/09 16:54:08 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_mlx_bmp(t_vars *vars)
{
	vars->img = (t_img *)malloc(sizeof(t_img));
	// 	// return (NULL);
	vars->mlx = mlx_init();
	// vars->win = mlx_new_window(vars->mlx, 1000, 1000, "Gogi joa");
	vars->img->img = mlx_new_image(vars->mlx, vars->scene->canvas.width, vars->scene->canvas.height);
	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bits_per_pixel, &vars->img->line_length, &vars->img->endian);
}

void	rendering_bmp(t_vars *vars)
{
	int		i;
	int		j;
	double	u;
	double	v;
	int		rgb;

	j = vars->scene->canvas.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < vars->scene->canvas.width)
		{
			u = (double)i / (vars->scene->canvas.width - 1);
			v = (double)j / (vars->scene->canvas.height - 1);
			vars->scene->ray = ray_primary(vars->scene->camera->element, u, v);
			rgb = create_rgb(ray_color(vars->scene));
			my_mlx_pixel_put(vars->img, vars->scene->canvas.width - i - 1, vars->scene->canvas.height - j - 1, rgb);
			i++;
		}
		j--;
	}
}

void	set_bitmap_file(t_vars *vars, int fd)
{
	int		tmp;
	char	bmp_file[14];
	char	bmp_info[40];

	ft_memset(&bmp_file, 0, 14);
	ft_memset(&bmp_info, 0, 40);
	ft_memmove(&bmp_file[0], "BM", 2);
	tmp = 54 + (vars->img->bits_per_pixel / 8) * vars->scene->canvas.width * vars->scene->canvas.height;
	ft_memmove(&bmp_file[2], &tmp, 4);
	tmp = 54;
	ft_memmove(&bmp_file[10], &tmp, 4);
	write(fd, bmp_file, 14);
	tmp = 40;
	ft_memmove(&bmp_info[0], &tmp, 4);
	ft_memmove(&bmp_info[4], &(vars->scene->canvas.width), 4);
	ft_memmove(&bmp_info[8], &(vars->scene->canvas.height), 4);
	tmp = 1;
	ft_memmove(&bmp_info[12], &tmp, 2);
	ft_memmove(&bmp_info[14], &(vars->img->bits_per_pixel), 2);
	write(fd, bmp_info, 40);
	// vars->bmp_file = (t_bitmapfileheader *)malloc(sizeof(t_bitmapfileheader));
	// vars->bmp_file->bf_type = 0x424D;
	// vars->bmp_file->bf_size = sizeof(t_bitmapfileheader) + sizeof(t_bitmapinfoheader) + (vars->scene->canvas.width * vars->scene->canvas.height * sizeof(int));
	// vars->bmp_file->bf_reserved1 = 0;
	// vars->bmp_file->bf_reserved2 = 0;
	// vars->bmp_file->bf_off_bits = sizeof(t_bitmapfileheader) + sizeof(t_bitmapinfoheader);
	// write(fd, &(vars->bmp_file), sizeof(t_bitmapfileheader));
}

// void	set_bitmap_info(t_vars *vars, int fd)
// {
// 	vars->bmp_info = (t_bitmapinfoheader *)malloc(sizeof(t_bitmapinfoheader));
// 	vars->bmp_info->bi_size = sizeof(t_bitmapinfoheader);
// 	vars->bmp_info->bi_width = vars->scene->canvas.width;
// 	vars->bmp_info->bi_height = vars->scene->canvas.height;
// 	vars->bmp_info->bi_planes = 1;
// 	vars->bmp_info->bi_bit_count = 32;
// 	vars->bmp_info->bi_compression = 0;
// 	vars->bmp_info->bi_size_image = sizeof(int) * vars->scene->canvas.width * vars->scene->canvas.height;
// 	vars->bmp_info->bi_x_pels_per_meter = vars->scene->canvas.width;
// 	vars->bmp_info->bi_y_pels_per_meter = vars->scene->canvas.height;
// 	vars->bmp_info->bi_clr_used = 0;
// 	vars->bmp_info->bi_clr_important = 0;
// 	write(fd, &(vars->bmp_info), sizeof(t_bitmapinfoheader));
// }

void	save_bitmap(t_vars *vars)
{
	int		fd;
	int		i;
	char	*img;

	fd = open("./image.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	set_bitmap_file(vars, fd);
	// set_bitmap_info(vars, fd);
	rendering_bmp(vars);
	i = 0;
	img = vars->img->addr;
	while (i < (vars->img->line_length / 4) * vars->scene->canvas.height)
	{
		if (i % (vars->img->line_length / 4) < vars->scene->canvas.width)
			write(fd, &img[i], 4);
		i++;
	}
}
