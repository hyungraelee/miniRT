/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:12:51 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/02 17:49:00 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "minirt.h"

int	parse_rt(char	*argv, t_scene *scene);
int	handle_info(char **info, t_scene *scene);
int	info_r(char	**info, t_scene *scene);
int	info_c(char **info, t_scene *scene);

int	ft_isright_info(char c);
int	check_info_err(char **info);

#endif
