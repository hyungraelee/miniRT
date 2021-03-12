/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:06:19 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 00:16:27 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_err_sp(char **info)
{
	if (count_info(info) != 4)
		return (0);
	if (ft_atoi(info[2]) < 0)
		return (0);
	return (1);
}

int	check_err_pl(char **info)
{
	if (count_info(info) != 4)
		return (0);
	return (1);
}

int	check_err_sq(char **info)
{
	if (count_info(info) != 5)
		return (0);
	if (ft_atoi(info[3]) < 0)
		return (0);
	return (1);
}

int	check_err_cy(char **info)
{
	if (count_info(info) != 6)
		return (0);
	if (ft_atoi(info[3]) < 0 || ft_atoi(info[4]) < 0)
		return (0);
	return (1);
}

int	check_err_tr(char **info)
{
	if (count_info(info) != 5)
		return (0);
	return (1);
}
