/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:55:53 by kmira             #+#    #+#             */
/*   Updated: 2019/06/07 18:10:48 by kmira            ###   ########.fr       */
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
	while (i < SIZE)
	{
		j = 0;
		while (j < number_x_point)
		{
			count = count_points(*line);
			printf("POINTS: %d\n", count);
			j++;
		}
		i++;
		get_next_line(file, line);
	}
}
