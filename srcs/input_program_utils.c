/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_program_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:32:54 by kmira             #+#    #+#             */
/*   Updated: 2019/06/17 13:41:43 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_points(char const *line)
{
	int		result;
	char	*color;
	int		i;

	i = 0;
	result = 0;
	while (line[i] != '\0')
	{
		SKIP_SPACE(line, i);
		if (ft_isdigit(line[i]) || line[i] == '-')
		{
			result++;
			if (line[i] == '-')
				i++;
			SKIP_DIGIT(line, i);
		}
		color = fetch_hexadecimal(&line[i]);
		if (color != NULL)
		{
			i += ft_strlen(color) + 3;
			free(color);
		}
		SKIP_SPACE(line, i);
		if (line[i] != '\0' && line[i] != '-' && ft_isdigit(line[i]) == 0)
			EXIT(RED"File is in an invalid format");
	}
	return (result);
}

int		count_rows(char const *file_name)
{
	size_t	result;
	char	*line;
	int		file;


	result = 0;
	line = NULL;
	file = open(file_name, O_RDONLY);
	while (get_next_line(file, &line) == 1)
	{
		free(line);
		result++;
	}
	close(file);
	return (result);
}
