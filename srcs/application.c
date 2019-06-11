/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 03:03:50 by kmira             #+#    #+#             */
/*   Updated: 2019/06/10 18:35:00 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define APPLICATION 0
#define POINTS 1
#define CAMERA 2

t_app	create_application(void)
{
	t_app	app;

	app.mlx_connection = mlx_init();
	app.window =
	mlx_new_window(app.mlx_connection, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	return (app);
}

int	key_pressed(int key, void **params)
{
	t_camera *camera;

	camera = params[2];
	if (key == 123)
	{
		printf("Left key was pressed\n");
		printf("PX Pre %d\n", camera->PX);
		camera->PX -= 1;
		printf("PX Post %d\n", camera->PX);
	}
	if (key == 124)
	{
		printf("Right key was pressed\n");
		camera->PX += 1;
	}
	if (key == 125)
	{
		printf("Down key was pressed\n");
		camera->PY += 1;
	}
	if (key == 126)
	{
		printf("UP key was pressed\n");
		camera->PY -= 1;
	}
	return (1);
}

int		events_handler(void **params)
{
	t_app	*application;

	application = params[APPLICATION];
	mlx_clear_window(application->mlx_connection, application->window);
	draw_lines(params[APPLICATION], params[POINTS], params[CAMERA]);
	return (1);
}
