/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:18:32 by kmira             #+#    #+#             */
/*   Updated: 2019/06/10 17:26:50 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_camera	create_camera(void)
{
	t_camera	camera;

	camera.rotation_x = 0;
	camera.rotation_y = 0;
	camera.PX = 0;
	camera.PY = 0;
	camera.PZ = 0;

	camera.target[X] = 0;
	camera.target[Y] = 0;
	camera.target[Z] = 0;

	return (camera);
}
