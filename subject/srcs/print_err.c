/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 23:52:08 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 15:34:04 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	print_err(int err_code)
{
	if (err_code == 0)
		printf("%s\n!!!!! Error in '.rt' file, \
		Please check the file.\n\n", C_RED);
	else if (err_code == -1)
		printf("%s\n!!!!! Error in memory allocation.\n\n", C_RED);
	return (0);
}
