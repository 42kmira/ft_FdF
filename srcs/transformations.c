/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:00:55 by kmira             #+#    #+#             */
/*   Updated: 2019/06/16 05:19:00 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	translate_point(t_point *point, t_camera camera)
{
	point->PX = point->PX - camera.PX;
	point->PY = point->PY - camera.PY;
}

#define CENTER 300

/*
** point->PY = (cos(x_angle) * (point->PY - CENTER))
**				- (sin(x_angle) * (point->PZ - CENTER));
** point->PZ = (sin(x_angle) * (tmp - CENTER))
**				+ (cos(x_angle) * (point->PZ - CENTER));
** point->PX = (cos(y_angle) * (point->PX - CENTER))
**				+ (sin(y_angle) * point->PZ - CENTER);
*/

void	rotate_point(t_point *point, t_camera camera)
{
	float	x_angle;
	float	y_angle;
	int		tmp;

	x_angle = (camera.rotation_angle_x * M_PI) / 180;
	y_angle = (camera.rotation_angle_y * M_PI) / 180;
	tmp = point->PY;
	point->PY = (cos(x_angle) * (point->PY)) - (sin(x_angle) * (point->PZ));
	point->PZ = (sin(x_angle) * (tmp)) + (cos(x_angle) * (point->PZ));
	point->PX = (cos(y_angle) * (point->PX)) + (sin(y_angle) * point->PZ);
}

void	scale_point(t_point *point, t_camera camera)
{
	point->PX = (int)(point->PX * camera.scaling[X]);
	point->PY = (int)(point->PY * camera.scaling[Y]);
	point->PZ = (int)(point->PZ * camera.scaling[Z]);
}
