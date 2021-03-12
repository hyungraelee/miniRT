/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:11:35 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/13 01:05:22 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	handle_info(char **info, t_scene *scene)
{
	if (!(check_info_err(info)))
		return (0);
	if (!(ft_strcmp(info[0], "R")))
		return (info_r(info, scene));
	else if (!(ft_strcmp(info[0], "A")))
		return (info_a(info, scene));
	else if (!(ft_strcmp(info[0], "c")))
		return (info_c(info, scene));
	else if (!(ft_strcmp(info[0], "l")))
		return (info_l(info, scene));
	else if (!(ft_strcmp(info[0], "sp")))
		return (info_sp(info, scene));
	else if (!(ft_strcmp(info[0], "pl")))
		return (info_pl(info, scene));
	else if (!(ft_strcmp(info[0], "sq")))
		return (info_sq(info, scene));
	else if (!(ft_strcmp(info[0], "cy")))
		return (info_cy(info, scene));
	else if (!(ft_strcmp(info[0], "tr")))
		return (info_tr(info, scene));
	else
		return (1);
}

int			parse_rt(char *argv, t_scene *scene)
{
	int		fd;
	int		ret;
	char	*line;
	char	**info;

	if ((fd = open(argv, O_RDONLY)) < 0)
		return (0);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		info = ft_split(line, ' ');
		if (!handle_info(info, scene))
		{
			free(line);
			free_split(info);
			return (0);
		}
		free(line);
		free_split(info);
	}
	free(line);
	close(fd);
	if (scene->cnt_r != 1 || scene->cnt_a != 1 \
	|| scene->cnt_c <= 0 || scene->cnt_l <= 0 || ret < 0)
		return (0);
	return (1);
}
