/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 18:14:25 by kmira             #+#    #+#             */
/*   Updated: 2019/06/05 20:59:36 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "debug.h"

# include "libft/libft.h"
# include "libft/ft_color.h"

# include <fcntl.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef EXIT
#  define EXIT(error_msg) ft_puterror(error_msg)
# endif

# define INVALID_FILE -1

int		count_points(char const *line);

#endif
