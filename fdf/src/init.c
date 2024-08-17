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


void	ft_add_point(int *coords, t_point **points)
{
	t_point	*point;
	t_point	*tmp_points;

	point = (t_point *)malloc(sizeof(t_point));
	point->x = coords[1];
	point->y = coords[0];
	point->z = coords[2];
	point->cor = coords[3];
	point->next = NULL;
	
	if (!(*points))
	{
		(*points) = point;
		return ;
	}
	tmp_points = *points;
	while (tmp_points && tmp_points->next)
	{
		tmp_points = tmp_points->next;
	}
	tmp_points->next = point;
}

void	ft_read_points(int fd, t_mapa **mapa)
{
	char	*tmp_line;
	char	**tmp_lines_mtz;
	int	coords[4];
	t_point *points;
	char			**partes;

	points = NULL;
	tmp_line = get_next_line(fd);
	while (tmp_line)
	{
		
		tmp_line = remove_new_line(tmp_line);
		tmp_lines_mtz = ft_split(tmp_line, ' ');
		if (tmp_lines_mtz && tmp_lines_mtz[0])
		{
			coords[0] = (*mapa)->height;
			coords[1] = 0;
			while (tmp_lines_mtz[coords[1]])
			{
				partes = ft_split(tmp_lines_mtz[coords[1]], ',');
				if (!ft_isnumber(partes[0], 10))
					terminate(ERR_MAP_READING);
				if (partes[1] && !ft_isnumber(partes[1], 16))
					terminate(ERR_MAP_READING);
				coords[2] = ft_atoi_base(partes[0], 10);
				coords[3] = -1;
				if (partes[1])
					coords[3] = ft_atoi_base(partes[1], 16);
				ft_add_point(coords, &points);			
				(coords[1])++;
			}
			if ((*mapa)->height == 0)
				(*mapa)->width = coords[1];
			if ((*mapa)->width != coords[1])
				terminate(ERR_MAP);
			(*mapa)->height++;
		}
		tmp_line = get_next_line(fd);
	}
	(*mapa)->pontos = points;
}

t_mapa	*mapa_init(int fd)
{
	t_mapa	*mapa;

	mapa = (t_mapa *) malloc(sizeof(t_mapa));
	if (!mapa)
		terminate(ERR_MAP_INIT);
	mapa->height = 0;
	mapa->width = 0;
	ft_read_points(fd, &mapa);
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
