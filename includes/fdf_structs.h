/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 16:22:00 by kmira             #+#    #+#             */
/*   Updated: 2019/06/17 00:47:54 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

# define PX pos[0]
# define PY pos[1]
# define PZ pos[2]

# define X 0
# define Y 1
# define Z 2

# define RGB rgb

typedef struct		s_point
{
	char			exist;
	char			id[2];

	int				pos[3];
	int				screen_pos[3];
	char			*color;
	int				rgb;
}					t_point;

typedef struct		s_app
{
	void			*mlx_connection;
	void			*window;
}					t_app;

typedef struct		s_camera
{
	int				rotation_angle_x;
	int				rotation_angle_y;
	float			scaling[3];
	int				pos[3];
	int				target[3];
}					t_camera;

typedef int	t_key_value;

typedef struct		s_keys
{
	int				key;
	t_key_value		flag;
	void			*modify;
	float			delta;
}					t_keys;

enum				e_keys
{
	KEY_UP = 0b00000000000010,
	KEY_DOWN = 0b00000000000100,
	KEY_LEFT = 0b00000000001000,
	KEY_RIGHT = 0b00000000010000,
	KEY_ROTATE_UP = 0b00000000100000,
	KEY_ROTATE_DOWN = 0b00000001000000,
	KEY_ROTATE_LEFT = 0b00000010000000,
	KEY_ROTATE_RIGHT = 0b00000100000000,
	KEY_INCREASE_ALT = 0b00001000000000,
	KEY_DECREASE_ALT = 0b00010000000000,
	KEY_ZOOM_IN = 0b00100000000000,
	KEY_ZOOM_OUT = 0b01000000000000,
	KEY_ESC = 0b10000000000000,
	UNDEFINED_KEY = 0b00000000000001
};

#endif
