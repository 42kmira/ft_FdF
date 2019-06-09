/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 22:06:04 by kmira             #+#    #+#             */
/*   Updated: 2019/06/09 00:08:40 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_point p1, t_point p2, t_app *app, int color)
{
	int cx = p2.x - p1.x;
	int cy = p2.y - p1.y;
	int i = p1.x;
	int j = p1.y;
	int sum;
	int move_y_by_one;

	sum = 0;
	while(i < p2.x)
	{
		sum += cy;
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
		i++;
		mlx_pixel_put(app->mlx_connection, app->window, i, j, 0xFF0000);
	}
	if (p1.color == NULL)
		mlx_string_put(app->mlx_connection, app->window, p1.x, p1.y, 0xFFFF00, p1.id);
	else
		mlx_string_put(app->mlx_connection, app->window, p1.x, p1.y, ft_atoi(p1.color), p1.id);
	if (p2.color == NULL)
		mlx_string_put(app->mlx_connection, app->window, p2.x, p2.y, 0xFFFF00, p2.id);
	else
		mlx_string_put(app->mlx_connection, app->window, p2.x, p2.y, ft_atoi(p2.color), p2.id);
	(void)color;
}
