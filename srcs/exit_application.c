/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_application.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 02:59:26 by kmira             #+#    #+#             */
/*   Updated: 2019/06/18 20:23:21 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	do_exit_sequence(void **params)
{
	int		i;
	t_point	**points;
	t_app	*app;

	i = 0;
	points = params[POINTS];
	app = params[APPLICATION];
	while (points[i] != NULL)
	{
		free(points[i]);
		i++;
	}
	free(points);
	free(params[KEY_DISPATCH_TABLE]);
	mlx_destroy_window(app->mlx_connection, app->window);
	system("leaks fdf");
	EXIT(GREEN"Program exited correctly");
}
