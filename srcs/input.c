/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:55:53 by kmira             #+#    #+#             */
/*   Updated: 2019/06/09 23:29:56 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define G_PIECE_ID

#include "fdf.h"
#include "fdf_structs.h"

#define SIZE 100

void	normalize_points(t_point **points, int cols, int rows)
{
	int		i;
	int		j;

	i = 0;
	while (points[i] != NULL)
	{
		j = 0;
		while (points[i][j].exist)
		{
			points[i][j].PX = ((WINDOW_WIDTH - (2 * OFFSET_X)) * j)
									/ (cols - 1) + OFFSET_X;
			points[i][j].PY = ((WINDOW_HEIGHT - (2 * OFFSET_Y)) * i)
									/ (rows - 1) + OFFSET_Y;
			points[i][j].PZ = ((WINDOW_WIDTH - (2 * OFFSET_X)) * j)
									/ (cols - 1) + OFFSET_X;
			j++;
		}
		i++;
	}
}

t_point	get_point(char const *line, int x, int y)
{
	t_point	result;

	result.exist = 1;

	result.PX = x;
	result.PY = y;
	result.PZ = ft_atoi(line);

	result.color = NULL;

	ft_bzero(result.id, 2);
	result.id[0] = g_piece_id;
	g_piece_id = g_piece_id + 1;
	if (g_piece_id == 'Z')
		g_piece_id = 'A';
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
	points[x].exist = 0;
	if (x == number_x_points)
		return (points);
	return (NULL);
}

t_point	**get_point_matrix(int file)
{
	int		row;
	t_point	**points;
	char	*line;
	int		number_x_points;

	get_next_line(file, &line);
	number_x_points = count_points(line);
	points = malloc(sizeof(*points) * (SIZE));
	row = 0;
	while (*line != '\0')
	{
		points[row] = get_row_of_points(line, row, number_x_points);
		get_next_line(file, &line);
		row++;
	}
	points[row] = NULL;
	normalize_points(points, number_x_points, row);
	return (points);
}
