/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:50:52 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/03 18:31:40 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "minirt.h"

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

# define BUFFER_SIZE 3

int		get_next_line(int fd, char **line);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	*ft_memcpy_gnl(void *dest, const void *src, size_t size);
size_t	ft_linelen(const char *s);
size_t	ft_strlen_gnl(const char *s);

#endif
