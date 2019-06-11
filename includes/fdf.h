/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 18:14:25 by kmira             #+#    #+#             */
/*   Updated: 2019/06/10 17:25:43 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** HEADERS
*/

# include "debug.h"

# include "libft.h"
# include "ft_color.h"
# include "fdf_structs.h"

# include "../minilibx_macos/mlx.h"

# include <fcntl.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** MARCOS
*/

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 740
# define WINDOW_NAME "FDF"

# define MULTIPLIER 25
# define OFFSET_X (WINDOW_WIDTH / 10)
# define OFFSET_Y (WINDOW_HEIGHT / 6)

# ifndef EXIT
#  define EXIT(error_msg) ft_puterror(error_msg)
# endif

# define INVALID_FILE -1

# define SKIP_SPACE(l, i) while ((l)[(i)] != '\0' && (l)[(i)] == ' ') (i)++;

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: input.c
*/

t_point	**get_point_matrix(int file);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: application.c
*/

t_app	create_application(void);
int		events_handler(void **params);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: camera.c
*/

t_camera	create_camera(void);


/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: rendering.c
** Handles on the image
*/

void	connect_points(t_point p1, t_point p2, t_app *app);
void	draw_lines(t_app *app, t_point **points, t_camera *camera);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: utils.c
** Handles intial steps.
*/

int		count_points(char const *line);
char	*fetch_hexadecimal(char const *string);
void	swap_point(t_point *p1, t_point *p2);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: transformation.c
** Does the matrix multiplication stuff.
*/

void	translate_point(t_point *point, t_camera camera);

#endif
