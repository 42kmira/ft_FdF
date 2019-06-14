/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:00:55 by kmira             #+#    #+#             */
/*   Updated: 2019/06/13 15:40:26 by kmira            ###   ########.fr       */
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


	/*
	** Applies the x_angle rotation. Rotating across the x-axis
	** x axis stays in place doesn't change.
	*/

	// //New PY
	// point->PY = (cos(x_angle) * point->PY);
	// point->PZ = (sin(x_angle) * point->PY);
	// //new PZ
	// point->PZ = (cos(x_angle) * point->PZ);
	// point->PY = (sin(x_angle) * point->PZ);
	// The added value of both
	int tmp;
	tmp = point->PY;

	point->PY = (cos(x_angle) * point->PY) + (sin(x_angle) * point->PZ);
	point->PZ = (sin(x_angle) * tmp) + (cos(x_angle) * point->PZ);

	/*
	** Based on the new points after the x-axis rotation the y-axis rotation is applied.
	** It is necessary for it to be applied on the new y-axis.
	*/

	// //New PZ
	// point->PX = (cos(y_angle) * point->PZ);
	// point->PZ = (sin(y_angle) * point->PZ);
	// //new PX
	// point->PX = (cos(y_angle) * point->PX);
	// point->PZ = (sin(y_angle) * point->PX);
	// The added value of both

	tmp = point->PX;
	point->PX = (cos(y_angle) * point->PZ) + (sin(y_angle) * point->PX);
	point->PZ = (sin(y_angle) * tmp) + (sin(y_angle) * point->PZ);

	// point->PX = (point->PY * (sin(x_angle))) + ((point->PX) * (cos(x_angle)));
	// point->PY = (point->PY * (cos(y_angle))) + ((point->PZ) * (cos(x_angle)));
	// point->PY = (point->PY * (cos(y_angle))) + ((point->PX) * (sin(y_angle)));
}
