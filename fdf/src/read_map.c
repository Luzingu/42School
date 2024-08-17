/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:20:20 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/11 09:20:22 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_coordenadas(t_mapa *map, t_coordenadas **coordenadas, int fd)
{
	char	**tmp_lines_mtz;
	char	*tmp_line;

	map->height = 0;
	tmp_line = get_next_line(fd);
	while (tmp_line)
	{
		tmp_line = remove_new_line(tmp_line);
		tmp_lines_mtz = ft_split(tmp_line, ' ');
		if (tmp_lines_mtz && tmp_lines_mtz[0])
		{
			ft_parse_line(tmp_lines_mtz, map, coordenadas);
			map->height++;
		}
		free(tmp_line);
		free_mtrx(tmp_lines_mtz);
		tmp_line = get_next_line(fd);
	}
	if (!(*coordenadas))
		terminate(ERR_MAP);
}

void	stack_to_map(t_coordenadas **coordenadas, t_mapa *mapa)
{
	t_coordenadas		*coord_ref;
	int					i;
	int					tamanho;

	tamanho = mapa->width * mapa->height * sizeof(int);
	mapa->coords_values = (int *) malloc(tamanho);
	if (!mapa->coords_values)
		terminate(ERR_CONV_TO_ARR);
	mapa->coords_colors = (int *) malloc(tamanho);
	if (!mapa->coords_colors)
		terminate(ERR_CONV_TO_ARR);
	i = 0;
	coord_ref = pop(coordenadas);
	while (coord_ref && i < mapa->width * mapa->height)
	{
		mapa->coords_values[i] = coord_ref->valor;
		mapa->coords_colors[i] = coord_ref->cor;
		if (coord_ref->valor > mapa->max_value)
			mapa->max_value = coord_ref->valor;
		if (coord_ref->valor < mapa->min_value)
			mapa->min_value = coord_ref->valor;
		i++;
		free(coord_ref);
		coord_ref = pop(coordenadas);
	}
}

void	ft_put_cord_stack(t_coordenadas **cordenadas, t_coordenadas *new_coord)
{
	t_coordenadas	*tmp_last;

	if (!new_coord)
		return ;
	if (!(*cordenadas))
	{
		(*cordenadas) = new_coord;
		return ;
	}
	tmp_last = *cordenadas;
	while (tmp_last && tmp_last->next)
	{
		tmp_last = tmp_last->next;
	}
	tmp_last->next = new_coord;
}

void	ft_handle_coord(char *line_part, t_coordenadas **cordenadas)
{
	t_coordenadas	*cord_tmp;
	char			**partes;

	cord_tmp = (t_coordenadas *)malloc(sizeof(t_coordenadas));
	if (!cord_tmp)
		terminate(ERR_MAP_READING);
	partes = ft_split(line_part, ',');
	if (!ft_isnumber(partes[0], 10))
		terminate(ERR_MAP_READING);
	if (partes[1] && !ft_isnumber(partes[1], 16))
		terminate(ERR_MAP_READING);
	cord_tmp->valor = ft_atoi_base(partes[0], 10);
	cord_tmp->cor = -1;
	if (partes[1])
		cord_tmp->cor = ft_atoi_base(partes[1], 16);
	cord_tmp->next = NULL;
	ft_put_cord_stack(cordenadas, cord_tmp);
	free_mtrx(partes);
}

void	ft_parse_line(char **line, t_mapa *map, t_coordenadas **cordenadas)
{
	int	i;
	int	width_tmp;

	i = 0;
	width_tmp = 0;
	while (line[i])
	{
		ft_handle_coord(line[i], cordenadas);
		i++;
		width_tmp++;
	}
	if (map->height == 0)
		map->width = width_tmp;
	if (map->width != width_tmp)
		terminate(ERR_MAP);
}
