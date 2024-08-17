/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revisao.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:55:07 by aluzingu          #+#    #+#             */
/*   Updated: 2024/07/15 11:55:08 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close(t_fdf *fdf)
{
	free(fdf->mapa->coords_colors);
	free(fdf->mapa->coords_values);
	free(fdf->mapa);
	free(fdf->camera);
	mlx_destroy_image(fdf->root, fdf->img);
	mlx_destroy_window(fdf->root, fdf->window);
	mlx_destroy_display(fdf->root);
	free(fdf->root);
	free(fdf);
	exit (0);
	return (0);
}

int	key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == KEY_ESC)
		ft_close(fdf);
	else if (key == KEY_ARROW_LEFT || key == KEY_ARROW_RIGHT
		|| key == KEY_ARROW_UP || key == KEY_ARROW_DOWN)
		move(key, fdf);
	else if (key == KEY_PLUS || key == KEY_MINUS)
		zoom(key, fdf);
	else if (key == KEY_2 || key == KEY_8 || key == KEY_6
		|| key == KEY_4 || key == KEY_1 || key == KEY_9)
		rotate(key, fdf);
	else if (key == KEY_MENORQUE || key == KEY_MAIORQUE)
		flatten(key, fdf);
	else if (key == KEY_I || key == KEY_P)
		change_projection(key, fdf);
	return (0);
}

void	setup_controls(t_fdf *fdf)
{
	mlx_key_hook(fdf->window, key_press, fdf);
	mlx_hook(fdf->window, 17, 0, ft_close, fdf);
}

int	main(int argc, char **argv)
{
	int				fd;
	t_coordenadas	*coordenadas;
	t_mapa			*mapa;
	t_fdf			*fdf;

	coordenadas = NULL;
	if (argc == 2)
	{
		if (!check_extension(argv[1]))
			terminate(ERR_MAP);
		fd = open(argv[1], O_RDONLY);
		if (fd == 0)
			terminate(ERR_MAP);
		mapa = mapa_init();
		get_coordenadas(mapa, &coordenadas, fd);
		stack_to_map(&coordenadas, mapa);
		fdf = fdf_init(mapa);
		fdf->camera = camera_init(fdf);
		draw(fdf, mapa);
		setup_controls(fdf);
		mlx_loop(fdf->root);
	}
	terminate(ERR_USAGE);
	return (0);
}
