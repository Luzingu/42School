#include "../include/core.h"


void	my_mlx_pixel_put(t_context *data, int x, int y, int color)
{
	char	*dst;

	dst = data->data + (y * data->size_line + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void    print_sky_floor(t_context *ctx)
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            if (y < HEIGHT / 2)
                my_mlx_pixel_put(ctx, x, y, rgb_to_hex(ctx->map.c ));
            else
                my_mlx_pixel_put(ctx, x, y, rgb_to_hex(ctx->map.f));
            x++;
        }
        y++; 
    }
}

void    ft_player_status(t_context *ctx, int x)
{ 
    double camera_x;

    camera_x  = 2 * x / (double)WIDTH - 1;
    ctx->raydir_x = ctx->dir_x + ctx->plane_x * camera_x; 
    ctx->raydir_y = ctx->dir_y + ctx->plane_y * camera_x;
    ctx->map_x = (int)ctx->pos_x;
    ctx->map_y = (int)ctx->pos_y;
    ctx->delta_dist_x = fabs(1 / ctx->raydir_x);
    ctx->delta_dist_y = fabs(1 / ctx->raydir_y);
    ctx->colision = 0;
}

void    init_ray_casting(t_context *ctx)
{
    int x;

    x = 0;
    print_sky_floor(ctx);
    while (x < WIDTH)
    {
        ft_player_status(ctx, x);
        ray_casting(ctx, x);
        x++;
    }
    mlx_put_image_to_window(ctx->inst, ctx->win, ctx->img, 0, 0);
}

int    ft_exit_program(t_context *ctx)
{
    ft_exit_free(ctx, NULL, NULL);
}

void    draw(t_context *ctx)
{
    define_player_position(ctx);
    init_ray_casting(ctx);
    mlx_hook(ctx->win, 17, 1L << 0, ft_exit_program, ctx);
    mlx_hook(ctx->win, 2, 1L << 0, key_press, ctx);
    mlx_loop(ctx->inst);
}