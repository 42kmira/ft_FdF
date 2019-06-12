/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:00:55 by kmira             #+#    #+#             */
/*   Updated: 2019/06/10 20:48:33 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	translate_point(t_point *point, t_camera camera)
{
	point->PX = point->PX + camera.PX;
	point->PY = point->PY + camera.PY;
	point->PZ = point->PZ + camera.PZ;
}

void	rotate_point(t_point *point, t_camera camera)
{
	float	x_angle;
	float	y_angle;

	x_angle = (camera.rotation_angle_x * M_PI * 2) / 360;
	y_angle = (camera.rotation_angle_y * M_PI * 2) / 360;

	point->PX = (point->PY * (sin(x_angle))) + (point->PX * (cos(x_angle)));
	point->PY = (point->PY * (cos(y_angle))) + (point->PX * (sin(y_angle)));
	point->PZ = point->PZ;
}
