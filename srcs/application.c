/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 03:03:50 by kmira             #+#    #+#             */
/*   Updated: 2019/06/16 23:12:57 by kmira            ###   ########.fr       */
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
	app.window = mlx_new_window(
					app.mlx_connection,
					WINDOW_WIDTH,
					WINDOW_HEIGHT,
					WINDOW_NAME);
	return (app);
}

int		key_pressed(int key, void **params)
{
	t_camera	*camera;
	t_app		*application;

	// printf("%d\n", key);
	camera = params[CAMERA];
	if (key == 123)
		camera->PX -= DELTA_TRANSLATE;
	if (key == 124)
		camera->PX += DELTA_TRANSLATE;
	if (key == 125)
		camera->PY += DELTA_TRANSLATE;
	if (key == 126)
		camera->PY -= DELTA_TRANSLATE;
	if (key == 91)
		camera->rotation_angle_x += DELTA_ROTATE;
	if (key == 84)
		camera->rotation_angle_x -= DELTA_ROTATE;
	if (key == 86)
		camera->rotation_angle_y += DELTA_ROTATE;
	if (key == 88)
		camera->rotation_angle_y -= DELTA_ROTATE;
	if (key == 47)
		camera->scaling[Z] += SCALING_DELTA;
	if (key == 43)
		camera->scaling[Z] -= SCALING_DELTA;
	if (key == 6)
	{
		camera->scaling[X] += SCALING_DELTA;
		camera->scaling[Y] += SCALING_DELTA;
		camera->scaling[Z] += SCALING_DELTA;
	}
	if (key == 7)
	{
		camera->scaling[X] -= SCALING_DELTA;
		camera->scaling[Y] -= SCALING_DELTA;
		camera->scaling[Z] -= SCALING_DELTA;
	}
	if (key == 53)
		EXIT(GREEN"Program is closing now");
	application = params[APPLICATION];
	mlx_clear_window(application->mlx_connection, application->window);
	draw_lines(params[APPLICATION], params[POINTS], params[CAMERA]);
	return (1);
}

#define PARAMS (void*[3]){(void *)&app, (void *)points, (void *)&camera}

void	application_loop(t_app app, t_point **points, t_camera camera)
{
	t_key_value keys;
	t_keys		*key_dispatch_table;

	keys = 0;
	key_dispatch_table = key_table(&camera);
	mlx_hook(app.window, 2, 0, toggle_flags_on, (void*[5]){(void *)&app, (void *)points, (void *)&camera, (void *)key_dispatch_table, (void *)&keys});
	mlx_hook(app.window, 3, 0, toggle_flags_off, (void*[5]){(void *)&app, (void *)points, (void *)&camera, (void *)key_dispatch_table, (void *)&keys});
	mlx_loop_hook(app.mlx_connection, render, (void*[5]){(void *)&app, (void *)points, (void *)&camera, (void *)key_dispatch_table, (void *)&keys});
	(void)points;
	mlx_loop(app.mlx_connection);
}
