/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:14:17 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/11 18:14:18 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	line_one_three(void)
{
	printf("#\t\t\t\t\t       #\n:\t\t\t\t\t       :\n+     ");
	printf("%s ", B_WHT);
	printf("%s\t\t       ", B_RESET);
	printf("%s   ", B_WHT);
	printf("%s\t       ", B_RESET);
	printf("%s  ", B_WHT);
	printf("%s      +\n", B_RESET);
	printf("#     ");
	printf("%s ", B_WHT);
	printf("%s\t\t      ", B_RESET);
	printf("%s ", B_WHT);
	printf("%s\t\t      ", B_RESET);
	printf("%s ", B_WHT);
	printf("%s  ", B_RESET);
	printf("%s ", B_WHT);
	printf("%s     #\n", B_RESET);
}

static void	line_four_six(void)
{
	printf(":     ");
	printf("%s ", B_WHT);
	printf("%s\t\t      ", B_RESET);
	printf("%s ", B_WHT);
	printf("%s\t\t      ", B_RESET);
	printf("%s ", B_WHT);
	printf("%s  ", B_RESET);
	printf("%s ", B_WHT);
	printf("%s     :\n", B_RESET);
	printf("+     ");
	printf("%s    ", B_WHT);
	printf("%s\t       ", B_RESET);
	printf("%s   ", B_WHT);
	printf("%s\t       ", B_RESET);
	printf("%s  ", B_WHT);
	printf("%s      +\n", B_RESET);
	printf("#\t\t\t\t\t       #\n");
	printf(":\t\t\t\t\t       :\n");
}

void	default_object(void)
{
	line_one_three();
	line_four_six();
}
