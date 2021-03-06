/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:25:13 by hyunlee           #+#    #+#             */
/*   Updated: 2021/02/28 17:53:12 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdio.h>
# include "structures.h"

void	write_color(t_color3 pixel_color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_rgb(t_color3 color);
void	rendering(t_scene *scene, t_data *img, t_vars *vars);

#endif
