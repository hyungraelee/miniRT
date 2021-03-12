/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_err_racl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 00:15:47 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 00:15:55 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			check_err_r(char **info)
{
	if (count_info(info) != 3)
		return (0);
	if (ft_atoi(info[1]) < 0 || ft_atoi(info[2]) < 0)
		return (0);
	return (1);
}

int			check_err_a(char **info)
{
	if (count_info(info) != 3)
		return (0);
	if (ft_atoi(info[1]) < 0 || ft_atoi(info[1]) > 1)
		return (0);
	return (1);
}

int			check_err_c(char **info)
{
	if (count_info(info) != 4)
		return (0);
	if (ft_atoi(info[3]) <= 0 || ft_atoi(info[3]) > 180)
		return (0);
	return (1);
}

int			check_err_l(char **info)
{
	if (count_info(info) != 4)
		return (0);
	if (ft_atoi(info[2]) < 0 || ft_atoi(info[2]) > 1)
		return (0);
	return (1);
}
