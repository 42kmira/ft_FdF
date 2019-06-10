/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 18:27:49 by kmira             #+#    #+#             */
/*   Updated: 2019/06/09 21:39:06 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include <stdio.h>

# include "fdf_structs.h"

void	db_print_points(t_point **points);
void	db_print_point_on_window(t_app *app, t_point p1, t_point p2);
void	db_print_line(t_point p1, t_point p2);

# ifdef G_PIECE_ID

char		g_piece_id = 'A';
# else

extern char	g_piece_id;
# endif

#endif
