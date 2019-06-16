/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:55:53 by kmira             #+#    #+#             */
/*   Updated: 2019/06/16 04:01:25 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_structs.h"

#define SIZE 100

/*
** Normalization of PZ is wrong. Needs to be fixed.
** Most likely we will need to find the max and do math on that
** points[i][j].PZ =
** 		((WINDOW_WIDTH - (2 * OFFSET_X)) * j) / (cols - 1) + OFFSET_X;
*/

void	normalize_points(t_point **points, int cols, int rows)
{
	int		i;
	int		j;

	i = 0;
	if (cols - 1 == 0)
		cols = 2;
	if (rows - 1 == 0)
		rows = 2;
	while (points[i] != NULL)
	{
		j = 0;
		while (points[i][j].exist)
		{
			points[i][j].PX =
				((WINDOW_WIDTH - (2 * OFFSET_X)) * j) / (cols - 1);
			points[i][j].PY =
				((WINDOW_HEIGHT - (2 * OFFSET_Y)) * i) / (rows - 1);
			j++;
		}
		i++;
	}
}

t_point	parse_point(char const *line, int x, int y, int *index)
{
	t_point	result;

	result.exist = 1;
	result.PX = x;
	result.PY = y;
	result.PZ = ft_atoi(&line[*index]);
	while (ft_isdigit(line[*index]))
		*index = *index + 1;
	if (line[*index] != '\0' && line[*index] != ',' && line[*index] != ' ')
		EXIT(RED"Invalid file format");
	result.RGB = 0xFFFFFF;
	if (result.PZ != 0)
		result.RGB = 0xFF0000;
	if (line[*index] == ',')
	{
		result.color = fetch_hexadecimal(&line[*index]);
		*index = *index + ft_strlen(result.color) + 3;
		result.RGB = a_to_color(result.color);
		free(result.color);
	}
	return (result);
}

t_point	*get_point_row(char const *line, int row, int number_x_points)
{
	t_point *point_row;
	int		x;
	int		i;

	point_row = malloc(sizeof(*point_row) * (number_x_points + 1));
	i = 0;
	x = 0;
	SKIP_SPACE(line, i);
	while (line[i] != '\0')
	{
		if (x > number_x_points)
			EXIT(RED"Invalid amount of points on a line");
		point_row[x] = parse_point(line, x, row, &i);
		SKIP_SPACE(line, i);
		x++;
	}
	point_row[x].exist = 0;
	if (x == number_x_points)
		return (point_row);
	else
		return (NULL);
}

/*
** Hardcoded SIZE needs to be changed to a linked list or a double read
** on the file.
*/

t_point	**create_point_matrix(int file)
{
	size_t	row;
	t_point	**points;
	int		new_line_read;
	char	*line;
	int		number_x_points;

	points = malloc(sizeof(*points) * (516));
	new_line_read = get_next_line(file, &line);
	number_x_points = count_points(line);
	row = 0;
	while (new_line_read)
	{
		points[row] = get_point_row(line, row, number_x_points);
		free(line);
		line = NULL;
		new_line_read = get_next_line(file, &line);
		row++;
	}
	free(line);
	close(file);
	points[row] = NULL;
	normalize_points(points, number_x_points, row);
	return (points);
}
