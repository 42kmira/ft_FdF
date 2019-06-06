/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:56:45 by kmira             #+#    #+#             */
/*   Updated: 2019/06/05 22:06:24 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_points(char const *line)
{
	int		result;
	char	color;
	int		i;

	i = 0;
	result = 0;
	// printf("%s\n", line);

	while (line[i] != '\0')
	{
		while (line[i] != '\0' && line[i] == ' ')
			i++;
		if (ft_isdigit(line[i]))
		{
			result++;
			while (line[i] != '\0' && ft_isdigit(line[i]))
				i++;
		}
		while (line[i] != '\0' && line[i] == ' ')
			i++;
		if (line[i] == ',')
		{
			color = hex_to_color(&line[i]);
			i += ft_strlen(color);
		}
		if (line[i] != '\0' && ft_isdigit(line[i]) == 0)
		{
			printf("Error %c\n", line[i]);
			EXIT(RED"File is in an invalid format\n");
		}
	}

	return (1);
}
