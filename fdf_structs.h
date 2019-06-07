/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 16:22:00 by kmira             #+#    #+#             */
/*   Updated: 2019/06/07 16:43:13 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
#define FDF_STRUCTS_H

# include "fdf.h"

typedef struct		s_point
{
	int				z;
	int				x;
	int				y;
	struct s_point	*next_x;
	struct s_point	*next_y;
	char			*color;
}					t_point;

// s_point *p_1;
// s_point *p_2;
// s_point	*p_y;

// while (p_y != NULL)
// {
// 	p_1 = p_y;
// 	p_2 = p_1->next_x;
// 	while (p_1->next_x != NULL)
// 	{
// 		draw_line(p_1, p_2);
// 		p_1 = p_1->next_x;
// 		p_2 = p_1->next_x;
// 	}
// 	p_y = p_y->next_y;
// }

#endif