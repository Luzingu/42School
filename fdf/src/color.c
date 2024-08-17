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

t_point	get_point(int x, int y, t_mapa *mapa)
{
	t_point	*tmp_points;
	t_point	ponto;

	tmp_points = mapa->pontos;
	while (tmp_points)
	{
		if (tmp_points->x == x && tmp_points->y == y)
		{
			ponto.x = tmp_points->x;
			ponto.y = tmp_points->y;
			ponto.z = tmp_points->z;
			ponto.cor = tmp_points->cor;
			if(ponto.cor == -1)
				ponto.cor = get_default_color(tmp_points->z, mapa);
			return (ponto);
		}
		tmp_points = tmp_points->next;
	}
	return (ponto);
}
