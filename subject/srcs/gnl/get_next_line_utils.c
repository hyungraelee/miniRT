/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:44:54 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 15:25:23 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_strlen_gnl(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin_gnl(char *save, char *buff)
{
	int		i;
	int		j;
	int		save_len;
	int		buff_len;
	char	*dest;

	save_len = ft_strlen_gnl(save);
	buff_len = ft_strlen_gnl(buff);
	if (!(dest = (char *)malloc(save_len + buff_len + 1)))
		return (NULL);
	i = -1;
	while (++i < save_len)
		dest[i] = save[i];
	j = -1;
	while (++j < buff_len)
		dest[i + j] = buff[j];
	dest[i + j] = '\0';
	free(save);
	return (dest);
}
