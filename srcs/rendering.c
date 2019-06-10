/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 22:06:04 by kmira             #+#    #+#             */
/*   Updated: 2019/06/09 21:00:56 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_point p1, t_point p2, t_app *app)
{
	int cx = p2.PX - p1.PX;
	int j = p1.PY;
	int sum;
	int move_y_by_one;

	sum = 0;
	while (p1.PX < p2.PX)
	{
		sum += (p2.PY - p1.PY);
		move_y_by_one = sum / cx;
		if (move_y_by_one == 1 || move_y_by_one == -1)
		{
			if (move_y_by_one == 1)
			{
				sum -= cx;
				j++;
			}
			else
			{
				sum += cx;
				j--;
			}
		}
		p1.PX += 1;
		mlx_pixel_put(app->mlx_connection, app->window, p1.PX, j, 0xFF0000);
	}
}

void		draw(t_app *app, t_point **points)
{
	int		i;
	int		j;

	i = 0;
	while (points[i] != NULL)
	{
		j = 1;
		while (points[i][j].exist)
		{
			draw_line(points[i][j - 1], points[i][j], app);
			j++;
		}
		i++;
	}
}