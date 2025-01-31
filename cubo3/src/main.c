/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebaptis <mebaptis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:18:49 by mebaptis          #+#    #+#             */
/*   Updated: 2025/01/22 11:18:33 by mebaptis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	ft_init(t_context *ctx)
{
	ctx->map.no = NULL;
	ctx->map.so = NULL;
	ctx->map.we = NULL;
	ctx->map.ea = NULL;
	ctx->map.f = NULL;
	ctx->map.c = NULL;
	ctx->free.str1 = NULL;
	ctx->free.str2 = NULL;
	ctx->free.str3 = NULL;
	ctx->free.mtx1 = NULL;
	ctx->free.mtx2 = NULL;
	ctx->free.mtx3 = NULL;
}

int	main(int argc, char **argv)
{
	t_context *ctx;
	ctx = (t_context *)malloc(sizeof(t_context) * 1);
	if (!ctx)
		ft_exit(ctx, "Error\nMalloc failed\n");
	if (argc != 2)
		ft_exit(ctx, "Error\nInvalid number of arguments\n");
	ft_init(ctx);
	ctx->inst = mlx_init();
	ft_read_file(argv[1], ctx);
	ctx->move_speed = 0.2;
	ctx->rot_speed = 0.2;
	ctx->win = mlx_new_window(ctx->inst, WIDTH, HEIGHT, "Cub3D");
	ctx->img = mlx_new_image(ctx->inst, WIDTH, HEIGHT);
	ctx->data = mlx_get_data_addr(ctx->img, &ctx->bpp, &ctx->size_line, &ctx->endian);
	define_player_position(ctx);
	draw(ctx);
	ft_free_ctx(ctx);
	return (0);
}