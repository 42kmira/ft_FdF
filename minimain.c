/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:31:18 by kmira             #+#    #+#             */
/*   Updated: 2019/06/17 14:21:32 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	// int i = 0;
	// float x_angle;

	// while (i < 360)
	// {
	// 	x_angle = (i * M_PI * 2) / 360;
	// 	printf("SIN: %f\n", sin(x_angle));
	// 	i++;
	// }

	printf("%ld\n", 4294967296);
	printf("%ju\n", 4294967296);
	char *line = malloc(sizeof(*line) * 10);
	line[9] = '\0';
	// free(line);
	return 0;
}
