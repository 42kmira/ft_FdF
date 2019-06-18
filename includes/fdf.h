/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 18:14:25 by kmira             #+#    #+#             */
/*   Updated: 2019/06/18 01:47:36 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** HEADERS
*/

# include "libft.h"
# include "ft_color.h"
# include "fdf_structs.h"

# include "../minilibx_macos/mlx.h"

# include <fcntl.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

#include <stdio.h>

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** MARCOS
*/

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000
# define WINDOW_NAME "FDF"

# define OFFSET_X (WINDOW_WIDTH / 6)
# define OFFSET_Y (WINDOW_HEIGHT / 4)

# define DELTA_SCALE 1
# define DELTA_ALTITUDE 50
# define DELTA_TRANSLATE 50
# define DELTA_ROTATE 7

# ifndef EXIT
#  define EXIT(error_msg) ft_puterror(error_msg)
# endif

# define INVALID_FILE -1

# define SKIP_SPACE(l, i) while ((l)[(i)] != '\0' && (l)[(i)] == ' ') (i)++;
# define SKIP_DIGIT(l, i) while ((l)[(i)] != '\0' && ft_isdigit(l[(i)])) (i)++;

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: input_program.c
*/

t_point		**create_point_matrix(int file, char const *file_name);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: input_program_utils.c
*/

int			count_rows(char const *file_name);
int			count_points(char const *line);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: application.c
*/

int			key_pressed(int key, void **params);
t_app		create_application(void);
int			events_handler(void **params);
void		application_loop(t_app app, t_point **points, t_camera camera);

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

void		connect_points(t_point p1, t_point p2, t_app *app);
void		draw_lines(t_app *app, t_point **points, t_camera *camera);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: utils.c
** Handles intial steps.
*/

char		*fetch_hexadecimal(char const *string);
void		swap_point(t_point *p1, t_point *p2);
int			a_to_color(char *color);
void		change_point(int move_by_one, int *sum, int delta, int *j);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: transformation.c
** Does the matrix multiplication stuff.
*/

void		translate_point(t_point *point, t_camera camera);
void		rotate_point(t_point *point, t_camera camera);
void		scale_point(t_point *point, t_camera camera);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: place_pixel.c
** Handles the color side of things
*/

int			get_color_delta(t_point p1, t_point p2, int x);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: input_application.c
** Handles user input as the program is running
*/

t_keys		*get_key_table(void);
int			toggle_flags_off(int key_pressed, void **params);
int			toggle_flags_on(int key_pressed, void **params);
int			render(void **params);

#endif
