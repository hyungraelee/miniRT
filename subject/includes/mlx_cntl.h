/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_cntl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:26:06 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/03 18:21:38 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_CNTL_H
# define MLX_CNTL_H

# include "minirt.h"

void	rendering(t_vars *vars);
void	set_mlx(t_vars *vars);
void	write_color(t_color3 pixel_color);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		create_rgb(t_color3 color);

#endif
