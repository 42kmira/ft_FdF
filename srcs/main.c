/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 18:13:33 by kmira             #+#    #+#             */
/*   Updated: 2019/06/07 23:02:39 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int aa, char const *argv[])
{
	char const	*file_name;
	int			file;
	int			number_x_points;
	char		*line;

	if (aa != 2)
		EXIT(RED"FdF usage: Invalid amount of arguements");
	file_name = argv[aa - 1];
	file = open(file_name, O_RDONLY);
	if (file == INVALID_FILE)
		EXIT(RED"File could not be opened");
	get_next_line(file, &line);
	number_x_points = count_points(line);

	t_point **points;
	points = get_point_matrix(file, number_x_points, &line);

	print_points(number_x_points, points);
	return (0);
}
