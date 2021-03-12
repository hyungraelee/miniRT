/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:48:43 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/13 00:50:24 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

void	free_all(t_vars *vars);
void	free_split(char **str);
void	free_list(t_object **obj);
void	free_scene(t_vars *vars);

#endif
