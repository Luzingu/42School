/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:26:31 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/11 09:26:32 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int	i;

	if (x < WIDTH && x >= MENU_WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * (fdf->bits_per_pixel / 8)) + (y * fdf->size_line);
		fdf->data_addr[i] = color;
		fdf->data_addr[++i] = color >> 8;
		fdf->data_addr[++i] = color >> 16;
	}
}

void	calculate_error(t_point *current, t_point *error,
t_point diff, t_point sentido)
{
	error->y = error->x * 2;
	if (error->y > -diff.y)
	{
		error->x -= diff.y;
		current->x += sentido.x;
	}
	if (error->y < diff.x)
	{
		error->x += diff.x;
		current->y += sentido.y;
	}
}

void	draw_line(t_point pt_start, t_point pt_end, t_fdf *fdf)
{
	t_point	diff;
	t_point	sentido;
	t_point	current;
	t_point	error;

	diff.x = ft_abs_value(pt_end.x - pt_start.x);
	diff.y = ft_abs_value(pt_end.y - pt_start.y);
	sentido.x = -1;
	if (pt_start.x < pt_end.x)
		sentido.x = 1;
	sentido.y = -1;
	if (pt_start.y < pt_end.y)
		sentido.y = 1;
	error.x = diff.x - diff.y;
	current = pt_start;
	while (current.x != pt_end.x || current.y != pt_end.y)
	{
		ft_put_pixel(fdf, current.x, current.y, current.cor);
		calculate_error(&current, &error, diff, sentido);
	}
}

void	recriate_image(t_fdf *fdf)
{
	int	*image;
	int	i;

	ft_bzero(fdf->data_addr, WIDTH * HEIGHT * (fdf->bits_per_pixel / 8));
	image = (int *)(fdf->data_addr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		image[i] = BACKGROUND;
		if (i % WIDTH < MENU_WIDTH)
			image[i] = MENU_BACKGROUND;
		i++;
	}
}

void	draw(t_fdf *fdf, t_mapa *mapa)
{
	int	x;
	int	y;

	y = 0;
	recriate_image(fdf);
	while (y < fdf->mapa->height)
	{
		x = 0;
		while (x < fdf->mapa->width)
		{
			if (x != fdf->mapa->width - 1)
				draw_line(project_iso(create_point(x, y, mapa), fdf),
					project_iso(create_point(x + 1, y, mapa), fdf), fdf);
			if (y != fdf->mapa->height -1)
				draw_line(project_iso(create_point(x, y, mapa), fdf),
					project_iso(create_point(x, y + 1, mapa), fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->root, fdf->window, fdf->img, 0, 0);
	print_menu(fdf);
}
