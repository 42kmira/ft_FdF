/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 03:03:50 by kmira             #+#    #+#             */
/*   Updated: 2019/06/08 23:56:16 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define APPLICATION 0
#define POINTS 1

int		draw(void **params)
{
	t_point	**points;
	int		i;
	int		j;
	int		color;

	points = (t_point **)(params[POINTS]);

	i = 0;
	while (points[i] != NULL)
	{
		j = 1;
		color = 0xFFFFFF;
		while (points[i][j].exist)
		{
			printf("Drawing point: (%3d,%3d,%3d) to (%3d,%3d,%3d)\n",
			points[i][j - 1].x, points[i][j - 1].y, points[i][j - 1].z,
			points[i][j].x, points[i][j].y, points[i][j].z);
			draw_line(points[i][j - 1], points[i][j], (t_app *)params[APPLICATION], color);
			j++;
		}
		i++;
	}
	return (1);
}

t_app	create_application(void)
{
	t_app	app;

	app.mlx_connection = mlx_init();
	app.window =
	mlx_new_window(app.mlx_connection, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	return (app);
}
