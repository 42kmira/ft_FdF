/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 22:06:04 by kmira             #+#    #+#             */
/*   Updated: 2019/06/16 15:25:58 by kmira            ###   ########.fr       */
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
	cx = p2.screen_pos[X] - p1.screen_pos[X];
	j = p1.screen_pos[Y];
	while (p1.screen_pos[X] < p2.screen_pos[X])
	{
		sum += (p2.screen_pos[Y] - p1.screen_pos[Y]);
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
		p1.screen_pos[X] += 1;
		mlx_pixel_put(app->mlx_connection, app->window, p1.screen_pos[X] + OFFSET_X, j + OFFSET_Y, DEF_COL);
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
	cy = p2.screen_pos[Y] - p1.screen_pos[Y];
	j = p1.screen_pos[X];
	while (p1.screen_pos[Y] < p2.screen_pos[Y])
	{
		sum += (p2.screen_pos[X] - p1.screen_pos[X]);
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
		p1.screen_pos[Y] += 1;
		mlx_pixel_put(app->mlx_connection, app->window, j + OFFSET_X, p1.screen_pos[Y] + OFFSET_Y, DEF_COL);
		DEF_COL = DEF_COL - color_delta;
	}
}

void	draw_line(t_point p1, t_point p2, t_app *app, t_camera *camera)
{
	int x_max;
	int y_max;

	x_max = p1.screen_pos[X] - p2.screen_pos[X];
	y_max = p1.screen_pos[Y] - p2.screen_pos[Y];
	if (p2.screen_pos[X] - p1.screen_pos[X] > x_max)
		x_max = p2.screen_pos[X] - p1.screen_pos[X];
	if (p2.screen_pos[Y] - p1.screen_pos[Y] > y_max)
		y_max = p2.screen_pos[Y] - p1.screen_pos[Y];
	if (x_max <= y_max)
	{
		if (p1.screen_pos[Y] > p2.screen_pos[Y])
			swap_point(&p1, &p2);
		connect_points_y(p1, p2, app);
	}
	else
	{
		if (p1.screen_pos[X] > p2.screen_pos[X])
			swap_point(&p1, &p2);
		connect_points_x(p1, p2, app);
	}
	(void)camera;
}

void	draw_lines(t_app *app, t_point **points, t_camera *camera)
{
	size_t	i;
	size_t	j;

	i = 0;
	// printf("Rendering once\n");
	while (points[i] != NULL)
	{
		j = 0;
		while (points[i][j].exist)
		{
			scale_point(&points[i][j], *camera);
			rotate_point(&points[i][j], *camera);
			translate_point(&points[i][j], *camera);
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
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