/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 03:03:50 by kmira             #+#    #+#             */
/*   Updated: 2019/06/17 14:49:09 by kmira            ###   ########.fr       */
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

#define VP void *
#define PARAMS (VP)&app, (VP)points, (VP)&camera, (VP)key_table, (VP)&keys

void	application_loop(t_app app, t_point **points, t_camera camera)
{
	t_key_value keys;
	t_keys		*key_table;

	keys = 0;
	key_table = get_key_table(&camera);
	mlx_hook(app.window, 2, 0, toggle_flags_on, (void*[5]){PARAMS});
	mlx_hook(app.window, 3, 0, toggle_flags_off, (void*[5]){PARAMS});
	mlx_loop_hook(app.mlx_connection, render, (void*[5]){PARAMS});
	mlx_loop(app.mlx_connection);
}
