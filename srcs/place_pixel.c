/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:05:57 by kmira             #+#    #+#             */
/*   Updated: 2019/06/13 21:52:39 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include  <math.h>

// void	place_pixel(t_point point, t_app *app)
// {
// 	int color;

// 	color = 0xFF00FF + (0x00FF00 / point.PZ);

// 	mlx_pixel_put(app->mlx_connection, app->window, j + OFFSET_X, p1.PY + OFFSET_Y, 0xFFFFFF);
// }


/*
** Color needs to be handled with a color or array.
** Can't return both a negatige RED delta and a positive BLUE change whilst another
** return is positive RED and negative BLUE.
*/

int		get_color_delta(t_point p1, t_point p2, int x)
{
	int r_channel;
	int b_channel;
	int g_channel;

	// printf("R: %d G: %d B: %d\n", (p1.RGB & 0xFF0000) >> 16, (p1.RGB & 0x00FF00) >> 8, (p1.RGB & 0x0000FF));

	r_channel = ((p1.RGB & 0xFF0000) >> 16) - ((p2.RGB & 0xFF0000) >> 16);
	g_channel = ((p1.RGB & 0x00FF00) >> 8) - ((p2.RGB & 0x00FF00) >> 8);
	b_channel = ((p1.RGB & 0x0000FF) >> 0) - ((p2.RGB & 0x0000FF) >> 0);

	printf("CHANGE R: %d G: %d B: %d\n", r_channel, g_channel, b_channel);
	if (x == 1)
	{
		if (p1.PX - p2.PX != 0)
		{
			r_channel = r_channel / (p2.PX - p1.PX);
			g_channel = g_channel / (p2.PX - p1.PX);
			b_channel = b_channel / (p2.PX - p1.PX);
		}
	}
	else
	{
		if (p1.PY - p2.PY != 0)
		{
			r_channel = r_channel / (p2.PY - p1.PY);
			g_channel = g_channel / (p2.PY - p1.PY);
			b_channel = b_channel / (p2.PY - p1.PY);
		}
	}
	return (
		(r_channel << 16) |
		(g_channel << 8) |
		(b_channel << 0)
		);
}
