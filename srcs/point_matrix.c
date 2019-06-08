/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:55:53 by kmira             #+#    #+#             */
/*   Updated: 2019/06/07 19:56:03 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_structs.h"

#define SIZE 10

void	get_point_matrix(int file, int number_x_point, char **line)
{
	int		i;
	int		j;
	int		count;
	t_point	**points;

	points = malloc(sizeof(*points) * (SIZE));
	i = 0;
	while (*line != '\0')
	{
		j = 0;
		count = count_points(*line);
		printf("POINTS: %d\n", count);
		while (j < number_x_point)
		{
			j++;
		}
		i++;
		get_next_line(file, line);
	}
}
