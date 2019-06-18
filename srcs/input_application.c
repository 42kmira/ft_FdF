/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_application.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 20:34:04 by kmira             #+#    #+#             */
/*   Updated: 2019/06/18 01:42:30 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_keys	*get_key_table(void)
{
	t_keys *key_dispatch;

	key_dispatch = malloc(sizeof(*key_dispatch) * (14));
	key_dispatch[0] = (t_keys){123, KEY_UP};
	key_dispatch[1] = (t_keys){124, KEY_DOWN};
	key_dispatch[2] = (t_keys){125, KEY_LEFT};
	key_dispatch[3] = (t_keys){126, KEY_RIGHT};

	key_dispatch[4] = (t_keys){91, KEY_ROTATE_UP};
	key_dispatch[5] = (t_keys){84, KEY_ROTATE_DOWN};
	key_dispatch[6] = (t_keys){86, KEY_ROTATE_LEFT};
	key_dispatch[7] = (t_keys){88, KEY_ROTATE_RIGHT};

	key_dispatch[8] = (t_keys){47, KEY_INCREASE_ALT};
	key_dispatch[9] = (t_keys){43, KEY_DECREASE_ALT};
	key_dispatch[10] = (t_keys){6, KEY_ZOOM_IN};
	key_dispatch[11] = (t_keys){7, KEY_ZOOM_OUT};

	key_dispatch[12] = (t_keys){53, KEY_ESC};

	return (key_dispatch);
}

#define APPLICATION 0
#define POINTS 1
#define CAMERA 2
#define KEY_DISPATCH_TABLE 3
#define KEYS_PRESSED 4

void	do_exit_sequence(void **params)
{
	(void)params;
	system("leaks fdf");
	EXIT(GREEN"Program exited correctly");
}

void	set_translate(t_key_value *keys_pressed, t_camera *camera)
{
	if (*keys_pressed & KEY_UP)
		camera->PX = camera->PX - DELTA_TRANSLATE;
	if (*keys_pressed & KEY_DOWN)
		camera->PX = camera->PX + DELTA_TRANSLATE;
	if (*keys_pressed & KEY_LEFT)
		camera->PY = camera->PY + DELTA_TRANSLATE;
	if (*keys_pressed & KEY_RIGHT)
		camera->PY = camera->PY - DELTA_TRANSLATE;
}

void	set_rotate(t_key_value *keys_pressed, t_camera *camera)
{
	if (*keys_pressed & KEY_ROTATE_UP)
		camera->rotation_angle_x = camera->rotation_angle_x - DELTA_ROTATE;
	if (*keys_pressed & KEY_ROTATE_DOWN)
		camera->rotation_angle_x = camera->rotation_angle_x + DELTA_ROTATE;
	if (*keys_pressed & KEY_ROTATE_LEFT)
		camera->rotation_angle_y = camera->rotation_angle_y - DELTA_ROTATE;
	if (*keys_pressed & KEY_ROTATE_RIGHT)
		camera->rotation_angle_y = camera->rotation_angle_y + DELTA_ROTATE;
}

void	set_scale(t_key_value *keys_pressed, t_camera *camera)
{
	if (*keys_pressed & KEY_INCREASE_ALT)
		camera->scaling[Z] = camera->scaling[Z] + DELTA_SCALE;
	if (*keys_pressed & KEY_DECREASE_ALT)
		camera->scaling[Z] = camera->scaling[Z] - DELTA_SCALE;
	if (*keys_pressed & KEY_ZOOM_IN)
	{
		camera->scaling[X] = camera->scaling[X] + DELTA_SCALE;
		camera->scaling[Y] = camera->scaling[Y] + DELTA_SCALE;
		if (camera->scaling[Z] > DELTA_SCALE)
			camera->scaling[Z] = camera->scaling[Z] + DELTA_SCALE;
		else if (camera->scaling[Z] < -DELTA_SCALE)
			camera->scaling[Z] = camera->scaling[Z] - DELTA_SCALE;
	}
	if (*keys_pressed & KEY_ZOOM_OUT)
	{
		camera->scaling[X] = camera->scaling[X] - DELTA_SCALE;
		camera->scaling[Y] = camera->scaling[Y] - DELTA_SCALE;
		if (camera->scaling[Z] < -DELTA_SCALE)
			camera->scaling[Z] = camera->scaling[Z] - DELTA_SCALE;
		else if (camera->scaling[Z] > DELTA_SCALE)
			camera->scaling[Z] = camera->scaling[Z] + DELTA_SCALE;
	}
}

int		render(void **params)
{
	t_camera	*camera;
	t_app		*application;
	t_key_value	*keys_pressed;

	camera = (t_camera *)(params[CAMERA]);
	keys_pressed = (t_key_value *)(params[KEYS_PRESSED]);
	set_translate(keys_pressed, camera);
	set_rotate(keys_pressed, camera);
	set_scale(keys_pressed, camera);
	if (*keys_pressed & KEY_ESC)
		do_exit_sequence(params);
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
