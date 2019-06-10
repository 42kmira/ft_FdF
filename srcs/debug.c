/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 22:56:25 by kmira             #+#    #+#             */
/*   Updated: 2019/06/09 21:39:37 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	db_print_points(t_point **points)
{
	int i;
	int j;

	i = 0;
	while (points[i] != NULL)
	{
		j = 0;
		printf("New line of points\n");
		while (points[i][j].exist)
		{
			printf("Point %3d,     (%-3d, %-3d, %-3d) color: %s\n", j,
			points[i][j].PX, points[i][j].PY, points[i][j].PZ, points[i][j].color);
			j++;
		}
		i++;
	}
}

void	db_print_point_on_window(t_app *app, t_point p1, t_point p2)
{
	mlx_string_put(app->mlx_connection, app->window, p1.PX, p1.PY, 0xFFFF00, p1.id);
	mlx_string_put(app->mlx_connection, app->window, p2.PX, p2.PY, 0xFFFF00, p2.id);
}

void	db_print_line(t_point p1, t_point p2)
{
	printf("Drawing point: (%3d,%3d,%3d) to (%3d,%3d,%3d)\n",
			p1.PX, p1.PY, p1.PZ,
			p2.PX, p2.PY, p2.PZ);
}
