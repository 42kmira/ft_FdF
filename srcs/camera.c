/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:18:32 by kmira             #+#    #+#             */
/*   Updated: 2019/06/16 14:29:05 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_camera	create_camera(void)
{
	t_camera	camera;

	camera.rotation_angle_x = 0;
	camera.rotation_angle_y = 0;
	camera.PX = 0;
	camera.PY = 0;
	camera.scaling[X] = 1;
	camera.scaling[Y] = 1;
	camera.scaling[Z] = 1;
	return (camera);
}
