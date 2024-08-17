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

void	draw_line2(t_point start, t_point end, t_fdf *fdf)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	delta.x = ft_abs_value(end.x - start.x);
	delta.y = ft_abs_value(end.y - start.y);
	sign.x = start.x < end.x ? 1 : -1;
	sign.y = start.y < end.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = start;
	while (cur.x != end.x || cur.y != end.y)
	{
		ft_put_pixel(fdf, cur.x, cur.y, cur.cor);
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
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
	
	recriate_image(fdf);
	
	y = 0;	
	while (y < fdf->mapa->height)
	{
		x = 0;
		while (x < fdf->mapa->width)
		{
			
			if ( y != fdf->mapa->height - 1)
				draw_line2(project_iso(get_point(x, y, mapa), fdf), project_iso(get_point(x, y + 1, mapa), fdf), fdf);
			
			if ( x != fdf->mapa->width - 1)
				draw_line2(project_iso(get_point(x, y, mapa), fdf), project_iso(get_point(x + 1, y, mapa), fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->root, fdf->window, fdf->img, 0, 0);
	print_menu(fdf);
}
