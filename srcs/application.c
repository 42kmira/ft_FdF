/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 03:03:50 by kmira             #+#    #+#             */
/*   Updated: 2019/06/13 21:54:00 by kmira            ###   ########.fr       */
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
		camera->PX -= 10;
	if (key == 124)
		camera->PX += 10;
	if (key == 125)
		camera->PY += 10;
	if (key == 126)
		camera->PY -= 10;

	if (key == 91)
		camera->rotation_angle_x += 1;
	if (key == 84)
		camera->rotation_angle_x -= 1;
	if (key == 86)
		camera->rotation_angle_y += 1;
	if (key == 88)
		camera->rotation_angle_y -= 1;

	if (key > 100)
		{}
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
