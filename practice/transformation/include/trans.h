/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:07:58 by hyunlee           #+#    #+#             */
/*   Updated: 2021/02/19 18:40:54 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANS_H
# define TRANS_H

# include "utils.h"

void	translate(t_object *obj, int axis, int sign);
void	scale(t_object *obj, int sign);

#endif
