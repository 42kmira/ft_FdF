/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:31:18 by kmira             #+#    #+#             */
/*   Updated: 2019/06/10 19:38:27 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int i = 0;
	float x_angle;

	while (i < 360)
	{
		x_angle = (i * M_PI * 2) / 360;
		printf("SIN: %f\n", sin(x_angle));
		i++;
	}
	return 0;
}
