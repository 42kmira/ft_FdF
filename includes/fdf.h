/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 18:14:25 by kmira             #+#    #+#             */
/*   Updated: 2019/06/07 18:13:17 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** HEADERS
*/

# include "debug.h"

# include "libft/libft.h"
# include "libft/ft_color.h"
# include "fdf_structs.h"

# include <fcntl.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** MARCOS
*/

# ifndef EXIT
#  define EXIT(error_msg) ft_puterror(error_msg)
# endif

# define INVALID_FILE -1

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: input.c
** Handles intial steps.
*/

int		count_points(char const *line);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: point_matrix.c
*/

void	get_point_matrix(int file, int number_x_point, char **line);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
*/

#endif
