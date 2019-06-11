/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:00:55 by kmira             #+#    #+#             */
/*   Updated: 2019/06/10 17:08:06 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_point(t_point *point, t_camera camera)
{
	point->PX = point->PX + camera.PX;
	point->PY = point->PY + camera.PY;
	point->PZ = point->PZ + camera.PZ;
}