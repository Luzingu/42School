/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:32:15 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/11 09:32:16 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_default_color(int valor, t_mapa *mapa)
{
	double	percentage;

	percentage = percent(mapa->min_value, mapa->max_value, valor);
	if (percentage < 0.2)
		return (COLOR_DISCO);
	else if (percentage < 0.4)
		return (COLOR_BRICK_RED);
	else if (percentage < 0.6)
		return (COLOR_FLAMINGO);
	else if (percentage < 0.8)
		return (COLOR_JAFFA);
	else
		return (COLOR_SAFFRON);
}

t_point	create_point(int x, int y, t_mapa *mapa)
{
	t_point	point;
	int		position;

	position = y * mapa->width + x;
	point.x = x;
	point.y = y;
	point.valor = mapa->coords_values[position];
	point.cor = mapa->coords_colors[position];
	if (point.cor == -1)
		point.cor = get_default_color(point.valor, mapa);
	return (point);
}
