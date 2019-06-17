/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_application.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 20:34:04 by kmira             #+#    #+#             */
/*   Updated: 2019/06/16 23:29:29 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define KEY(NAME) { char_ ## NAME, FLAG_ ## NAME}

t_keys	*key_table(t_camera *camera)
{
	t_keys *key_dispatch;

	key_dispatch = malloc(sizeof(*key_dispatch) * (14));
	key_dispatch[0]  = (t_keys){123,	KEY_UP,				&camera->PX,				-DELTA_TRANSLATE};
	key_dispatch[1]  = (t_keys){124,	KEY_DOWN,			&camera->PX,				DELTA_TRANSLATE};
	key_dispatch[2]  = (t_keys){125,	KEY_LEFT,			&camera->PY,				DELTA_TRANSLATE};
	key_dispatch[3]  = (t_keys){126,	KEY_RIGHT,			&camera->PY,				-DELTA_TRANSLATE};
	key_dispatch[4]  = (t_keys){91,		KEY_ROTATE_UP,		&camera->rotation_angle_x,	-DELTA_ROTATE};
	key_dispatch[5]  = (t_keys){84,		KEY_ROTATE_DOWN,	&camera->rotation_angle_x,	DELTA_ROTATE};
	key_dispatch[6]  = (t_keys){86,		KEY_ROTATE_LEFT,	&camera->rotation_angle_y,	DELTA_ROTATE};
	key_dispatch[7]  = (t_keys){88,		KEY_ROTATE_RIGHT,	&camera->rotation_angle_y,	-DELTA_ROTATE};
	key_dispatch[8]  = (t_keys){47,		KEY_INCREASE_ALT,	&camera->scaling[Z],		SCALING_DELTA};
	key_dispatch[9]  = (t_keys){43,		KEY_DECREASE_ALT,	&camera->scaling[Z],		-SCALING_DELTA};
	key_dispatch[10] = (t_keys){6,		KEY_ZOOM_IN,		NULL,						SCALING_DELTA};
	key_dispatch[11] = (t_keys){7,		KEY_ZOOM_OUT,		NULL,						SCALING_DELTA};
	key_dispatch[12] = (t_keys){53,		KEY_ESC,			NULL,						0};
	key_dispatch[13] = (t_keys){0,		UNDEFINED_KEY,		NULL,						0};
	return (key_dispatch);
}

#define APPLICATION 0
#define POINTS 1
#define CAMERA 2

int		render(void **params)
{
	size_t		i;
	t_keys		*key_dispatch_table;
	t_camera	*camera;
	t_key_value *keys;

	i = 0;
	keys = (t_key_value *)(params[4]);
	camera = (t_camera *)(params[1]);
	key_dispatch_table = (t_keys *)(params[3]);
	while (key_dispatch_table[i].flag != UNDEFINED_KEY)
	{
		if (*keys & key_dispatch_table[i].flag)
		{
			if (key_dispatch_table[i].flag == KEY_DECREASE_ALT || key_dispatch_table[i].flag == KEY_INCREASE_ALT)
				*(float *)key_dispatch_table[i].modify = *(float *)key_dispatch_table[i].modify + key_dispatch_table[i].delta;
			else if (key_dispatch_table[i].flag != KEY_ZOOM_IN && key_dispatch_table[i].flag != KEY_ZOOM_OUT && key_dispatch_table[i].flag != KEY_ESC)
				*(int *)key_dispatch_table[i].modify = *(int *)key_dispatch_table[i].modify + key_dispatch_table[i].delta;
		}
		i++;
	}
	t_app		*application;
	application = params[APPLICATION];
	mlx_clear_window(application->mlx_connection, application->window);
	draw_lines(params[APPLICATION], params[POINTS], params[CAMERA]);
	return (1);
}

int		toggle_flags_on(int key_pressed, void **params)
{
	size_t		i;
	t_keys		*key_dispatch_table;
	t_key_value *keys;

	i = 0;
	keys = (t_key_value *)(params[4]);
	key_dispatch_table = (t_keys *)(params[3]);
	while (key_dispatch_table[i].key != 0)
	{
		if (key_pressed == key_dispatch_table[i].key)
			*keys = (*keys) | key_dispatch_table[i].flag;
		i++;
	}
	return (1);
}

int		toggle_flags_off(int key_pressed, void **params)
{
	size_t		i;
	t_keys		*key_dispatch_table;
	t_key_value *keys;

	i = 0;
	keys = (t_key_value *)(params[4]);
	key_dispatch_table = (t_keys *)(params[3]);
	while (key_dispatch_table[i].flag != UNDEFINED_KEY)
	{
		if (key_pressed == key_dispatch_table[i].key)
			*keys = (*keys) ^ key_dispatch_table[i].flag;
		i++;
	}
	return (1);
}
