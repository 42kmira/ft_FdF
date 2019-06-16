/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 22:06:04 by kmira             #+#    #+#             */
/*   Updated: 2019/06/16 04:57:23 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define DEF_COL p1.RGB

void	connect_points_x(t_point p1, t_point p2, t_app *app)
{
	int cx;
	int j;
	int sum;
	int move_y_by_one;
	int color_delta;

	color_delta = get_color_delta(p1, p2, 1);

	sum = 0;
	cx = p2.PX - p1.PX;
	j = p1.PY;
	while (p1.PX < p2.PX)
	{
		sum += (p2.PY - p1.PY);
		move_y_by_one = sum / cx;
		if (move_y_by_one >= 1 || move_y_by_one <= -1)
		{
			if (move_y_by_one >= 1)
			{
				sum -= cx;
				j = j + 1;
			}
			else
			{
				sum += cx;
				j = j - 1;
			}
		}
		p1.PX += 1;
		mlx_pixel_put(app->mlx_connection, app->window, p1.PX + OFFSET_X, j + OFFSET_Y, DEF_COL);
		DEF_COL = DEF_COL - color_delta;
	}
}

void	connect_points_y(t_point p1, t_point p2, t_app *app)
{
	int cy;
	int j;
	int sum;
	int move_x_by_one;
	int color_delta;

	color_delta = get_color_delta(p1, p2, 0);

	sum = 0;
	cy = p2.PY - p1.PY;
	j = p1.PX;
	while (p1.PY < p2.PY)
	{
		sum += (p2.PX - p1.PX);
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
		mlx_pixel_put(app->mlx_connection, app->window, j + OFFSET_X, p1.PY + OFFSET_Y, DEF_COL);
		DEF_COL = DEF_COL - color_delta;
	}
}

void		draw_line(t_point p1, t_point p2, t_app *app, t_camera *camera)
{
	int x_max;
	int y_max;
	/*	TRANSFORM POINTS HERE	*/
	//Scaling need to be done before rotation or translation.
	scale_point(&p1, *camera);
	scale_point(&p2, *camera);

	//Rotation needs to be calculated before translation
	//Rotation transform
	rotate_point(&p1, *camera);
	rotate_point(&p2, *camera);

	//Translation transform
	// translate_point(&p1, *camera);
	// translate_point(&p2, *camera);


	//Clip space point
	//3D to 2D transform

	//pick algorithm
	x_max = p1.PX - p2.PX;
	y_max = p1.PY - p2.PY;

	if (p2.PX - p1.PX > x_max)
		x_max = p2.PX - p1.PX;
	if (p2.PY - p1.PY > y_max)
		y_max = p2.PY - p1.PY;


	if (x_max <= y_max)
	{
		if (p1.PY > p2.PY)
			swap_point(&p1, &p2);
		connect_points_y(p1, p2, app);
	}
	else
	{
		if (p1.PX > p2.PX)
			swap_point(&p1, &p2);
		connect_points_x(p1, p2, app);
	}
	(void)camera;
}

/*
** One loop to do both horizontal and veritcal line drawing
*/
	// mlx_clear_window(g_mp, g_wp);
	// g_c.y = g_mh;
	// while (--g_c.y >= 0)
	// {
	// 	g_c.x = g_mw;
	// 	while (--g_c.x >= 0)
	// 	{
	// 		if (g_c.y != g_mh - 1)
	// 			connect(g_c.x, g_c.y, g_c.x, g_c.y + 1);
	// 		if (g_c.x != g_mw - 1)
	// 			connect(g_c.x, g_c.y, g_c.x + 1, g_c.y);
	// 	}
	// }

void		draw_lines(t_app *app, t_point **points, t_camera *camera)
{
	int		i;
	int		j;

	// i = 0;
	// j = 0;
	// while (points[i] != NULL)
	// {
	// 	j = 0;
	// 	while (points[i][j].exist)
	// 	{
	// 		scale_point(&points[i][j], *camera);
	// 		rotate_point(&points[i][j], *camera);
	// 		translate_point(&points[i][j], *camera);
	// 		j++;
	// 	}
	// 	i++;
	// }
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
