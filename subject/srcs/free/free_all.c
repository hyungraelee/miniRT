/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:08:52 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/13 01:44:11 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_list(t_object **obj)
{
	t_object	*tmp;
	t_object	*cur;

	if (obj == NULL || *obj == NULL)
		return ;
	cur = *obj;
	while (cur->next)
	{
		tmp = cur;
		free(tmp->element);
		cur = cur->next;
		free(tmp);
	}
	free(cur->element);
	free(cur);
}

void	free_scene(t_vars *vars)
{
	if (vars->scene == NULL)
		return ;
	free(vars->scene);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_all(t_vars *vars)
{
	free_list(&vars->scene->camera);
	free_list(&vars->scene->light);
	free_list(&vars->scene->world);
	free(vars->scene);
	free(vars->img);
	free(vars->mode);
}
