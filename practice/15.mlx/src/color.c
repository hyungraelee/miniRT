/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:17:56 by hyunlee           #+#    #+#             */
/*   Updated: 2021/02/28 17:52:26 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/print.h"

void	write_color(t_color3 pixel_color)
{
	printf("%d %d %d\n", (int)(255.999 * pixel_color.x), (int)(255.999 * pixel_color.y), (int)(255.999 * pixel_color.z));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		create_rgb(t_color3 color)
{
	int r;
	int g;
	int b;

	r = (int)(255.999 * color.x);
	g = (int)(255.999 * color.y);
	b = (int)(255.999 * color.z);
	return (0 << 24 | r << 16 | g << 8 | b);
}
