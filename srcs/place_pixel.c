/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:05:57 by kmira             #+#    #+#             */
/*   Updated: 2019/06/16 15:29:17 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include  <math.h>

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


	r_channel = ((p1.RGB & 0xFF0000) >> 16) - ((p2.RGB & 0xFF0000) >> 16);
	g_channel = ((p1.RGB & 0x00FF00) >> 8) - ((p2.RGB & 0x00FF00) >> 8);
	b_channel = ((p1.RGB & 0x0000FF) >> 0) - ((p2.RGB & 0x0000FF) >> 0);

	if (x == 1)
	{
		if (p1.screen_pos[X] - p2.screen_pos[X] != 0)
		{
			r_channel = r_channel / (p2.screen_pos[X] - p1.screen_pos[X]);
			g_channel = g_channel / (p2.screen_pos[X] - p1.screen_pos[X]);
			b_channel = b_channel / (p2.screen_pos[X] - p1.screen_pos[X]);
		}
	}
	else
	{
		if (p1.screen_pos[Y] - p2.screen_pos[Y] != 0)
		{
			r_channel = r_channel / (p2.screen_pos[Y] - p1.screen_pos[Y]);
			g_channel = g_channel / (p2.screen_pos[Y] - p1.screen_pos[Y]);
			b_channel = b_channel / (p2.screen_pos[Y] - p1.screen_pos[Y]);
		}
	}
	return (
		(r_channel << 16) |
		(g_channel << 8) |
		(b_channel << 0)
		);
}
