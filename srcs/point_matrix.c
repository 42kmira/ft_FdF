/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:55:53 by kmira             #+#    #+#             */
/*   Updated: 2019/06/07 23:13:57 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_structs.h"

#define SIZE 100

t_point	get_point(char const *line, int x, int y)
{
	t_point	result;

	result.x = x;
	result.y = y;
	result.z = ft_atoi(line);
	result.color = NULL;
	return (result);
}

t_point	*get_row_of_points(char const *line, int y, int number_x_points)
{
	t_point	*points;
	int		x;
	int		i;

	i = 0;
	x = 0;
	points = malloc(sizeof(*points) * (number_x_points + 1));
	SKIP_SPACE(line, i);
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]))
		{
			points[x] = get_point(&line[i], x, y);
			while (ft_isdigit(line[i]))
				i++;
			points[x].color = fetch_hexadecimal(&line[i]);
			if (points[x].color != NULL)
				i += ft_strlen(points[x].color) + 3;
			x++;
		}
		SKIP_SPACE(line, i);
		if (line[i] != '\0' && ft_isdigit(line[i]) == 0)
			EXIT(RED"Invalid file: see format\n");
	}
	if (x == number_x_points)
		return (points);
	return (NULL);
}

t_point	**get_point_matrix(int file, int number_x_point, char **line)
{
	int		row;
	t_point	**points;

	points = malloc(sizeof(*points) * (SIZE));
	row = 0;
	while (**line != '\0')
	{
		points[row] = get_row_of_points(*line, row, number_x_point);
		get_next_line(file, line);
		row++;
	}
	points[row] = NULL;
	return (points);
}
