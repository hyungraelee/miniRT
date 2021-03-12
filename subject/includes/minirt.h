/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:34:18 by hyunlee           #+#    #+#             */
/*   Updated: 2021/03/12 15:28:41 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include "structures.h"
# include "scene.h"
# include "parse.h"
# include "utils.h"
# include "mlx_cntl.h"
# include "trace.h"
# include "trans.h"
# include "key_macos.h"
# include "libft.h"
# include "mlx.h"
# include "bitmap.h"
# include "panel.h"
# include "get_next_line.h"

int		minirt(char *argv, t_vars *vars);
t_scene	*scene_init();
int		print_err(int err_code);
#endif
