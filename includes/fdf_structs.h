/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 16:22:00 by kmira             #+#    #+#             */
/*   Updated: 2019/06/09 21:06:02 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

# define PX pos[0]
# define PY pos[1]
# define PZ pos[2]

typedef struct		s_point
{
	char			exist;
	char			id[2];

	int				pos[3];
	char			*color;
}					t_point;

typedef struct		s_app
{
	void			*mlx_connection;
	void			*window;
}					t_app;

typedef struct		s_camera
{
	int				rotation_x;
	int				rotaion_y;
	int				pos[3];
	int				target[3];
}					t_camera;

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