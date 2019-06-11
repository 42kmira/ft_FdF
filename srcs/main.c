/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 18:13:33 by kmira             #+#    #+#             */
/*   Updated: 2019/06/10 18:42:53 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	key_pressed(int key, void **params)
// {
// 	t_camera *camera;

// 	camera = params[2];
// 	if (key == 121)
// 		printf("somehwere above 2\n");
// 	if (key == 122)
// 		printf("somehwere above 3\n");
// 	if (key == 123)
// 		printf("somehwere above 4\n");
// 	if (key == 124)
// 		printf("somehwere above 5\n");
// 	if (key == 125)
// 		printf("somehwere above 6\n");
// 	if (key == 126)
// 		printf("somehwere above 7\n");
// 	if (key == 127)
// 		printf("somehwere above 8\n");
// 	if (key == 128)
// 		printf("somehwere above 9\n");
// 	if (key == 129)
// 		printf("somehwere above 10\n");

// 	(void)params;
// 	return (1);
// }

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
	points = get_point_matrix(file);
	app = create_application();
	camera = create_camera();
	// prepration_step()
	mlx_hook (app.window, 2, 0, key_pressed, (void*[3]){(void *)&app, (void *)points, (void *)&camera});
	mlx_loop_hook(app.mlx_connection, events_handler, (void*[3]){(void *)&app, (void *)points, (void *)&camera});
	mlx_loop(app.mlx_connection);
	return (0);
}
