/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:00:55 by kmira             #+#    #+#             */
/*   Updated: 2019/06/16 15:13:08 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

/*
** point->PY = (cos(x_angle) * (point->PY - CENTER))
**				- (sin(x_angle) * (point->PZ - CENTER));
** point->PZ = (sin(x_angle) * (tmp - CENTER))
**				+ (cos(x_angle) * (point->PZ - CENTER));
** point->PX = (cos(y_angle) * (point->PX - CENTER))
**				+ (sin(y_angle) * point->PZ - CENTER);
*/

void	translate_point(t_point *point, t_camera camera)
{
	point->screen_pos[X] = point->screen_pos[X] - camera.PX;
	point->screen_pos[Y] = point->screen_pos[Y] - camera.PY;
}

#define CENTER 300

void	rotate_point(t_point *point, t_camera camera)
{
	float	x_angle;
	float	y_angle;
	int		tmp;

	x_angle = (camera.rotation_angle_x * M_PI) / 180;
	y_angle = (camera.rotation_angle_y * M_PI) / 180;
	tmp = point->screen_pos[Y];
	point->screen_pos[Y] = (cos(x_angle) * (point->screen_pos[Y])) - (sin(x_angle) * (point->screen_pos[Z]));
	point->screen_pos[Z] = (sin(x_angle) * (tmp)) + (cos(x_angle) * (point->screen_pos[Z]));
	point->screen_pos[X] = (cos(y_angle) * (point->screen_pos[X])) + (sin(y_angle) * point->screen_pos[Z]);
}

void	scale_point(t_point *point, t_camera camera)
{
	point->screen_pos[X] = (int)(point->PX * camera.scaling[X]);
	point->screen_pos[Y] = (int)(point->PY * camera.scaling[Y]);
	point->screen_pos[Z] = (int)(point->PZ * camera.scaling[Z]);
}
