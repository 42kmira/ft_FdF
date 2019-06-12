/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 22:06:04 by kmira             #+#    #+#             */
/*   Updated: 2019/06/11 20:39:30 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	connect_points_x(t_point p1, t_point p2, t_app *app)
{
	int cx = p2.PX - p1.PX;
	int cy = p2.PY - p1.PY;
	int j = p1.PY;
	int sum;
	int move_y_by_one;

	sum = 0;

	while (p1.PX < p2.PX)
	{
		sum += (p2.PY - p1.PY);
		move_y_by_one = sum / cx;
		// printf("SUM: %d and move: %d\n", sum, move_y_by_one);
		if (move_y_by_one >= 1 || move_y_by_one <= -1)
		{
			if (move_y_by_one >= 1)
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
	(void)cy;
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

void	connect_points_y(t_point p1, t_point p2, t_app *app)
{
	int cy = p2.PY - p1.PY;
	int cx = p2.PX - p1.PX;
	int j = p1.PX;
	int sum;
	int move_x_by_one;

	sum = 0;

	while (p1.PY < p2.PY)
	{
		sum += (cx);
		move_x_by_one = sum / cy;
		if (move_x_by_one >= 1 || move_x_by_one <= -1)
		{
			if (move_x_by_one >= 1)
			{
				sum -= cy;
				j = j + 1;
			}
			else
			{
				sum += cy;
				j = j - 1;
			}
		}
		p1.PY += 1;
		mlx_pixel_put(app->mlx_connection, app->window, j, p1.PY, 0x0000FF);
	}
}

void		draw_line(t_point p1, t_point p2, t_app *app, t_camera *camera)
{
	int x_max;
	int y_max;
	/*	TRANSFORM POINTS HERE	*/
	//Rotation needs to be calculated before translation
	//Rotation transform

	//Translation transform
	translate_point(&p1, *camera);
	translate_point(&p2, *camera);

	rotate_point(&p1, *camera);
	rotate_point(&p2, *camera);

	//Clip space point
	//3D to 2D transform

	//pick algorithm
	x_max = p1.PX - p2.PX;
	y_max = p1.PY - p2.PY;

	if (p2.PX - p1.PX > x_max)
		x_max = p2.PX - p1.PX;
	if (p2.PY - p1.PY > y_max)
		y_max = p2.PY - p1.PY;

	if (p1.PX == p2.PX)
		draw_vertical_line(p1, p2, app);
	else if (x_max >= y_max)
	{
		if (p1.PX > p2.PX)
			swap_point(&p1, &p2);
		connect_points_x(p1, p2, app);
	}
	else
	{
		if (p1.PY > p2.PY)
			swap_point(&p1, &p2);
		connect_points_y(p1, p2, app);
	}
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
