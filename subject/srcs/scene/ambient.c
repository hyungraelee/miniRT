/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:52:09 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/05 13:11:18 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ambient	ambient(double ratio, t_color3 color)
{
	t_ambient	ambient;

	ambient.ratio = ratio;
	ambient.ambient_color = color;
	return (ambient);
}
