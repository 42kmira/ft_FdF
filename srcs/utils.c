/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:56:45 by kmira             #+#    #+#             */
/*   Updated: 2019/06/16 14:30:06 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		hex_prefixed(char const *str)
{
	if (str == NULL)
		return (0);
	if (str[0] == '0' && (str[1] == 'X' || str[1] == 'x'))
		return (1);
	else
		return (0);
}

char	*fetch_hexadecimal(char const *string)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	if (string[i] == ',')
	{
		if (hex_prefixed(&string[++i]))
		{
			i += 2;
			j = 0;
			while (ft_ishex(string[i + j]))
				j++;
			result = malloc(sizeof(*result) * (j + 3));
			j = -1;
			while (ft_ishex(string[++j + i]))
				result[j] = string[j + i];
			result[j] = '\0';
			return (result);
		}
		return (NULL);
	}
	else
		return (NULL);
}

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
		if (ft_isdigit(line[i]))
		{
			result++;
			while (line[i] != '\0' && ft_isdigit(line[i]))
				i++;
		}
		color = fetch_hexadecimal(&line[i]);
		if (color != NULL)
			i += ft_strlen(color) + 3;
		SKIP_SPACE(line, i);
		if (line[i] != '\0' && ft_isdigit(line[i]) == 0)
			EXIT(RED"File is in an invalid format\n");
	}
	return (result);
}

void	swap_point(t_point *p1, t_point *p2)
{
	t_point tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int		a_to_color(char *color)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (color[i] != '\0')
	{
		result = result << 4;
		if (ft_isdigit(color[i]))
			result = result + (color[i] - '0');
		if ('a' <= ft_tolower(color[i]) && ft_tolower(color[i]) <= 'f')
			result = result + (ft_tolower(color[i]) - 'a') + 10;
		i++;
	}
	return (result);
}
