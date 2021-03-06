/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:11:35 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 00:12:43 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	handle_info(char **info, t_scene *scene)
{
	if (!(check_info_err(info)))
		return (0);
	if (!(ft_strcmp(info[0], "R")))
		return(info_r(info, scene));
	else if (!(ft_strcmp(info[0], "A")))
		return(info_a(info, scene));
	else if (!(ft_strcmp(info[0], "c")))
		return(info_c(info, scene));
	else if (!(ft_strcmp(info[0], "l")))
		return(info_l(info, scene));
	else if (!(ft_strcmp(info[0], "sp")))
		return(info_sp(info, scene, &scene->world));
	else if (!(ft_strcmp(info[0], "pl")))
		return(info_pl(info, scene, &scene->world));
	else if (!(ft_strcmp(info[0], "sq")))
		return(info_sq(info, scene, &scene->world));
	else if (!(ft_strcmp(info[0], "cy")))
		return(info_cy(info, scene, &scene->world));
	else if (!(ft_strcmp(info[0], "tr")))
		return(info_tr(info, scene, &scene->world));
	else
		return (1);
}

int			parse_rt(char *argv, t_scene *scene)
{
	int		fd;
	int		ret;
	char	*line;
	char	**info;

	fd = open(argv, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		info = ft_split(line,' ');
		if (!handle_info(info, scene))
			return (0);
		free(line);
		free(info);
	}
	if (ret < 0)
		return (0);
	return (1);
}
