/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:13:50 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/08 14:03:17 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	oadd(t_object **list, t_object *new)
{
	t_object	*cur;
	void		*pre;

	if(*list == NULL)
	{
		*list = new;
		new->pre = NULL;
		return ;
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	pre = cur;
	cur->next = new;
	new->pre = pre;
}
