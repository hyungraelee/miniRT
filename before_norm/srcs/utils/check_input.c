/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 23:53:26 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/11 23:53:32 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_input_file(char *argv)
{
	char	*str;

	str = ft_strrev(argv);
	if (ft_strncmp(str, "tr.", 3))
		return (0);
	str = ft_strrev(argv);
	return (1);
}
