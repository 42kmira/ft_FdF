/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 03:03:50 by kmira             #+#    #+#             */
/*   Updated: 2019/06/09 20:59:35 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define APPLICATION 0
#define POINTS 1

t_app	create_application(void)
{
	t_app	app;

	app.mlx_connection = mlx_init();
	app.window =
	mlx_new_window(app.mlx_connection, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	return (app);
}

int		events_handler(void **params)
{
	draw(params[APPLICATION], params[POINTS]);
	return (1);
}