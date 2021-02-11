/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:16:32 by hyunlee           #+#    #+#             */
/*   Updated: 2021/01/20 16:31:15 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/trace.h"

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	// 광선의 방향벡터와 교점의 법선벡터의 내적이 음수이면 광선은 객체의 앞면에 hit 한 것임.
	rec->front_face = vdot(r->dir, rec->normal) < 0;
	// 광선의 앞면에 hit 했으면 법선벡터 그대로, 아니면 반대로 뒤집는다.(왜..?) (항상 광선의 방향벡터와 법선 벡터를 반대인 상태로 사용하기 위해)
	rec->normal = (rec->front_face) ? rec->normal : vmul(rec->normal, -1);
}
