/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:08:01 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/11 09:08:02 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

t_camera	*camera_init(t_fdf *fdf)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		terminate(ERR_CAMERA_INIT);
	camera->zoom = ft_min((WIDTH - MENU_WIDTH) / fdf->mapa->width / 2,
			HEIGHT / fdf->mapa->height / 2);
	camera->angle_rot_x = 0;
	camera->angle_rot_y = 0;
	camera->angle_rot_z = 0;
	camera->z_divisor = 2;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->projection = 'I';
	return (camera);
}

t_mapa	*mapa_init(void)
{
	t_mapa	*mapa;

	mapa = (t_mapa *) malloc(sizeof(t_mapa));
	if (!mapa)
		terminate(ERR_MAP_INIT);
	mapa->height = 0;
	mapa->width = 0;
	mapa->coords_values = NULL;
	mapa->coords_colors = NULL;
	mapa->max_value = INT_MIN;
	mapa->min_value = INT_MAX;
	return (mapa);
}

t_fdf	*fdf_init(t_mapa *mapa)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		terminate(ERR_FDF_INIT);
	fdf->root = mlx_init();
	fdf->window = mlx_new_window(fdf->root, WIDTH, HEIGHT, "FdF");
	fdf->img = mlx_new_image(fdf->root, WIDTH, HEIGHT);
	fdf->mapa = mapa;
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
			&(fdf->size_line), &(fdf->endian));
	return (fdf);
}
