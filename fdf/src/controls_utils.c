/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:34:24 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/11 09:34:47 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move(int key, t_fdf *fdf)
{
	if (key == KEY_ARROW_LEFT)
		fdf->camera->x_offset -= 10;
	else if (key == KEY_ARROW_RIGHT)
		fdf->camera->x_offset += 10;
	else if (key == KEY_ARROW_UP)
		fdf->camera->y_offset -= 10;
	else
		fdf->camera->y_offset += 10;
	draw(fdf, fdf->mapa);
}

void	zoom(int key, t_fdf *fdf)
{
	if (key == KEY_PLUS)
		fdf->camera->zoom++;
	else if (key == KEY_MINUS)
		fdf->camera->zoom--;
	if (fdf->camera->zoom < 1)
		fdf->camera->zoom = 1;
	draw(fdf, fdf->mapa);
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == KEY_2)
		fdf->camera->angle_rot_x += 0.05;
	else if (key == KEY_8)
		fdf->camera->angle_rot_x -= 0.05;
	else if (key == KEY_4)
		fdf->camera->angle_rot_y -= 0.05;
	else if (key == KEY_6)
		fdf->camera->angle_rot_y += 0.05;
	else if (key == KEY_1)
		fdf->camera->angle_rot_z += 0.05;
	else if (key == KEY_9)
		fdf->camera->angle_rot_z -= 0.05;
	draw(fdf, fdf->mapa);
}

void	flatten(int key, t_fdf *fdf)
{
	if (key == KEY_MENORQUE)
		fdf->camera->z_divisor -= 0.1;
	else if (key == KEY_MAIORQUE)
		fdf->camera->z_divisor += 0.1;
	if (fdf->camera->z_divisor < 0.1)
		fdf->camera->z_divisor = 0.1;
	else if (fdf->camera->z_divisor > 10)
		fdf->camera->z_divisor = 10;
	draw(fdf, fdf->mapa);
}

void	change_projection(int key, t_fdf *fdf)
{
	fdf->camera->angle_rot_x = 0;
	fdf->camera->angle_rot_y = 0;
	fdf->camera->angle_rot_z = 0;
	if (key == KEY_I)
		fdf->camera->projection = 'I';
	else if (key == KEY_P)
		fdf->camera->projection = 'P';
	draw(fdf, fdf->mapa);
}
