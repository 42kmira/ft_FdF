/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 18:13:33 by kmira             #+#    #+#             */
/*   Updated: 2019/06/18 20:18:53 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int aa, char const *argv[])
{
	char const	*file_name;
	int			file;
	t_point		**points;
	t_app		app;
	t_camera	camera;

	if (aa != 2)
		EXIT(RED"FdF usage: Invalid amount of arguements");
	file_name = argv[aa - 1];
	file = open(file_name, O_RDONLY);
	if (file == INVALID_FILE)
		EXIT(RED"File could not be opened");
	points = create_point_matrix(file, file_name);
	camera = create_camera();
	app = create_application();
	draw_lines(&app, points, &camera);
	application_loop(app, points, camera);
	return (0);
}
