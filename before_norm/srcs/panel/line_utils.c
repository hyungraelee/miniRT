/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:14:21 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/11 18:14:22 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	top_bottom_panel(void)
{
	printf("+#:+#:+#:+#:");
	printf("+#:+#:+#:+#:");
	printf("+#:+#:+#:+#:");
	printf("+#:+#:+#:+#:");
	printf("\n");
}

void	next_previous_panel(int selected)
{
	printf("+----------------------------------------------+\n");
	printf("#   ");
	if (selected == OFF)
		printf("<-previous");
	else
		printf("%s<-previous", C_YLW);
	printf("%s\t\t\t      ", C_RESET);
	if (selected == OFF)
		printf("next->");
	else
		printf("%snext->", C_YLW);
	printf("%s   #\n", C_RESET);
	printf(":----------------------------------------------:\n");
}
