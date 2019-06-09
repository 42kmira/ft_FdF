/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 18:13:33 by kmira             #+#    #+#             */
/*   Updated: 2019/06/09 00:04:08 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int aa, char const *argv[])
{
	char const	*file_name;
	int			file;
	t_point		**points;
	t_app		app;

	if (aa != 2)
		EXIT(RED"FdF usage: Invalid amount of arguements");
	file_name = argv[aa - 1];
	file = open(file_name, O_RDONLY);
	if (file == INVALID_FILE)
		EXIT(RED"File could not be opened");
	points = get_point_matrix(file);
	print_points(points);
	app = create_application();
	mlx_loop_hook(app.mlx_connection, draw, (void*[2]){(void *)&app, (void *)points});
	mlx_loop(app.mlx_connection);
	return (0);
}
