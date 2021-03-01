/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:33:10 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/01 20:52:43 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include <stdio.h>

int	open_rt(char	*argv)
{

}

int main(int	argc, char	*argv[])
{
	// t_vars	vars;
	int		fd;
	int		ret;
	char	*line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
	// parse_rt(argv[1]);
		while ((ret = get_next_line(fd, &line)) > 0)
    	{
    	    printf("%s\n", line);
    	    free(line);
    	}
    	printf("%s\n", line);
    	free(line);
	}
    return (0);
}
