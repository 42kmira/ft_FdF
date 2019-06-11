/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 22:06:04 by kmira             #+#    #+#             */
/*   Updated: 2019/06/10 18:35:35 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	connect_points(t_point p1, t_point p2, t_app *app)
{
	int cx = p2.PX - p1.PX;
	int j = p1.PY;
	int sum;
	int move_y_by_one;

	db_print_point_on_window(app, p1, p2);

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

void		draw_vertical_line(t_point p1, t_point p2, t_app *app)
{
	int	delta;

	delta = 1;
	if (p1.PY > p2.PY)
		delta = -1;
	while (p1.PY != p2.PY)
	{
		mlx_pixel_put(app->mlx_connection, app->window, p1.PX, p1.PY, 0xFF0000);
		p1.PY = p1.PY + delta;
	}
}

void		draw_line(t_point p1, t_point p2, t_app *app, t_camera *camera)
{
	/*	TRANSFORM POINTS HERE	*/

	//Rotation transform
	//Translation transform

	translate_point(&p1, *camera);
	translate_point(&p2, *camera);
	//Clip space point
	//3D to 2D transform

	//pick algorithm
	if (p1.PX > p2.PX)
		swap_point(&p1, &p2);
	if (p1.PX == p2.PX)
		draw_vertical_line(p1, p2, app);
	else
		connect_points(p1, p2, app);
}

void		draw_lines(t_app *app, t_point **points, t_camera *camera)
{
	int		i;
	int		j;

	i = 0;
	while (points[i] != NULL)
	{
		j = 1;
		while (points[i][j].exist)
		{
			draw_line(points[i][j - 1], points[i][j], app, camera);
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (points[i] != NULL && points[i][j].exist)
	{
		i = 1;
		while (points[i] != NULL)
		{
			draw_line(points[i - 1][j], points[i][j], app, camera);
			i++;
		}
		i = 0;
		j++;
	}
}
