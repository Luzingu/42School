/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:36:39 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/11 09:36:40 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (previous_x + previous_y) * sin(0.523599) - z;
}

void	rotate_x(int *y, int *z, double alpha)
{
	int	previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(int *x, int *z, double beta)
{
	int	previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(int *x, int *y, double gamma)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

t_point	project_iso(t_point p, t_fdf *fdf)
{
	
	p.x *= fdf->camera->zoom;
	p.y *= fdf->camera->zoom;
	
	p.x -= (fdf->mapa->width * fdf->camera->zoom) / 2;
	p.y -= (fdf->mapa->height * fdf->camera->zoom) / 2;
	p.z *= fdf->camera->zoom / fdf->camera->z_divisor;
	if (fdf->camera->projection == 'I')
		iso(&p.x, &p.y, p.z);
	rotate_x(&p.y, &p.z, fdf->camera->angle_rot_x);
	rotate_y(&p.x, &p.z, fdf->camera->angle_rot_y);
	rotate_z(&p.x, &p.y, fdf->camera->angle_rot_z);
	p.y += fdf->camera->y_offset +  (HEIGHT + fdf->mapa->height * fdf->camera->zoom) / 2 - 100;
	p.x += fdf->camera->x_offset + (WIDTH - MENU_WIDTH) / 2 + MENU_WIDTH;
	return (p);
}
