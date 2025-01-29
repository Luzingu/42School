/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omorkoc <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:20:01 by omorkoc           #+#    #+#             */
/*   Updated: 2022/08/31 14:43:17 by omorkoc          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_map2(t_cub3d *s_cub3d, int x)
{
	int		y;
	int		color;

	// Calcula a distância perpendicular da parede
	if (s_cub3d->raydir_x < 0)
	{
		s_cub3d->step_x = -1;
		s_cub3d->side_dist_x = (s_cub3d->pos_x - s_cub3d->map_x) * s_cub3d->delta_dist_x;
	}
	else
	{
		s_cub3d->step_x = 1;
		s_cub3d->side_dist_x = (s_cub3d->map_x + 1.0 - s_cub3d->pos_x) * s_cub3d->delta_dist_x;
	}
	if (s_cub3d->raydir_y < 0)
	{
		s_cub3d->step_y = -1;
		s_cub3d->side_dist_y = (s_cub3d->pos_y - s_cub3d->map_y) * s_cub3d->delta_dist_y;
	}
	else
	{
		s_cub3d->step_y = 1;
		s_cub3d->side_dist_y = (s_cub3d->map_y + 1.0 - s_cub3d->pos_y) * s_cub3d->delta_dist_y;
	}

	// Detecta a colisão com uma parede
	while (s_cub3d->hit == 0)
	{
		if (s_cub3d->side_dist_x < s_cub3d->side_dist_y)
		{
			s_cub3d->side_dist_x += s_cub3d->delta_dist_x;
			s_cub3d->map_x += s_cub3d->step_x;
			s_cub3d->side = 0;
		}
		else
		{
			s_cub3d->side_dist_y += s_cub3d->delta_dist_y;
			s_cub3d->map_y += s_cub3d->step_y;
			s_cub3d->side = 1;
		}
		if (s_cub3d->map3[s_cub3d->map_x][s_cub3d->map_y] == 1)
			s_cub3d->hit = 1;
	}

	// Calcula a distância perpendicular da parede
	if (s_cub3d->side == 0)
		s_cub3d->perp_wall_dist = (s_cub3d->map_x - s_cub3d->pos_x + (1 - s_cub3d->step_x) / 2) / s_cub3d->raydir_x;
	else
		s_cub3d->perp_wall_dist = (s_cub3d->map_y - s_cub3d->pos_y + (1 - s_cub3d->step_y) / 2) / s_cub3d->raydir_y;

	// Calcula a altura da linha a ser desenhada e a posição da textura
	s_cub3d->line_height = (int)(WIN_HEIGHT / s_cub3d->perp_wall_dist);
	s_cub3d->draw_start = -s_cub3d->line_height / 2 + WIN_HEIGHT / 2;
	if (s_cub3d->draw_start < 0)
		s_cub3d->draw_start = 0;
	s_cub3d->draw_end = s_cub3d->line_height / 2 + WIN_HEIGHT / 2;
	if (s_cub3d->draw_end >= WIN_HEIGHT)
		s_cub3d->draw_end = WIN_HEIGHT - 1;

	if (s_cub3d->side == 0)
		s_cub3d->wall_x = s_cub3d->pos_y + s_cub3d->perp_wall_dist * s_cub3d->raydir_y;
	else
		s_cub3d->wall_x = s_cub3d->pos_x + s_cub3d->perp_wall_dist * s_cub3d->raydir_x;
	s_cub3d->wall_x -= floor(s_cub3d->wall_x);
	s_cub3d->tex_x = (int)(s_cub3d->wall_x * (double)IMG_WIDTH);

	// Ajusta a textura de acordo com a direção do raio
	if (s_cub3d->side == 0 && s_cub3d->raydir_x > 0)
		s_cub3d->tex_x = IMG_WIDTH - s_cub3d->tex_x - 1;
	if (s_cub3d->side == 1 && s_cub3d->raydir_y < 0)
		s_cub3d->tex_x = IMG_WIDTH - s_cub3d->tex_x - 1;
 
	// Passo para a textura e posição inicial da textura
	s_cub3d->step = 1.0 * IMG_HEIGHT / s_cub3d->line_height;
	s_cub3d->tex_pos = (s_cub3d->draw_start - WIN_HEIGHT / 2 + s_cub3d->line_height / 2) * s_cub3d->step;

	// Desenha a parede pixel a pixel
	y = s_cub3d->draw_start;
	while (y < s_cub3d->draw_end &&  s_cub3d->draw_start == 238)
	{
		s_cub3d->tex_y = (int)s_cub3d->tex_pos & (IMG_HEIGHT - 1);
		s_cub3d->tex_pos += s_cub3d->step;
		color = 0;
		
		if (s_cub3d->raydir_y < 0 && s_cub3d->side == 1)
		{
			color = s_cub3d->imgs_data[1][IMG_HEIGHT * s_cub3d->tex_y + s_cub3d->tex_x];
		}
		else if (s_cub3d->raydir_x < 0 && s_cub3d->side == 0)
			color = s_cub3d->imgs_data[2][IMG_HEIGHT * s_cub3d->tex_y + s_cub3d->tex_x];
		else if (s_cub3d->raydir_y > 0 && s_cub3d->side == 1)
		{
			color = s_cub3d->imgs_data[0][IMG_HEIGHT * s_cub3d->tex_y + s_cub3d->tex_x];
			printf("Color: %d, text_x: %d, text_y: %d, Step: %f\n", color, s_cub3d->tex_x, s_cub3d->tex_y, s_cub3d->perp_wall_dist);
		}
		else if (s_cub3d->raydir_x > 0 && s_cub3d->side == 0)
			color = s_cub3d->imgs_data[3][IMG_HEIGHT * s_cub3d->tex_y + s_cub3d->tex_x];
			
		s_cub3d->screen_img_data[y * WIN_WIDTH + x] = color;
		y++;
	}
}

