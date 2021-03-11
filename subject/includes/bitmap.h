/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:39:02 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/11 14:25:08 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
# define BITMAP_H


int		bitmap(char *argv, t_vars *vars);
void	save_bitmap(t_vars *vars);
int		set_mlx_bmp(t_vars *vars);

#endif
