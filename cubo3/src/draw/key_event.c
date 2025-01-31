
#include "../include/core.h"

void	move_player(t_context *ctx, double move_x, double move_y)
{
	double new_x = ctx->pos_x + move_x * ctx->move_speed;
	double new_y = ctx->pos_y + move_y * ctx->move_speed;

	if (ctx->map.map[(int)ctx->pos_y][(int)new_x] != '1')
		ctx->pos_x = new_x;
	if (ctx->map.map[(int)new_y][(int)ctx->pos_x] != '1')
		ctx->pos_y = new_y;
}

void	rotate_player(t_context *ctx, double angle)
{
	double olddir_x = ctx->dir_x;
	double oldplane_x = ctx->plane_x;
	double cos_theta = cos(angle);
	double sin_theta = sin(angle);

	ctx->dir_x = ctx->dir_x * cos_theta - ctx->dir_y * sin_theta;
	ctx->dir_y = olddir_x * sin_theta + ctx->dir_y * cos_theta;
	ctx->plane_x = ctx->plane_x * cos_theta - ctx->plane_y * sin_theta;
	ctx->plane_y = oldplane_x * sin_theta + ctx->plane_y * cos_theta;
}

int	key_press(int keycode, t_context *ctx)
{
	if (keycode == 65307)
		ft_exit_free(ctx, NULL, NULL);
	else if (keycode == UP)
		move_player(ctx, ctx->dir_x, ctx->dir_y);
	else if (keycode == DOWN)
		move_player(ctx, -ctx->dir_x, -ctx->dir_y);
	else if (keycode == LEFT)
		move_player(ctx, -ctx->plane_x, -ctx->plane_y);
	else if (keycode == RIGHT)
		move_player(ctx, ctx->plane_x, ctx->plane_y);
	else if (keycode == LEFT_ROTATE)
		rotate_player(ctx, ctx->rot_speed);
	else if (keycode == RIGHT_ROTATE)
		rotate_player(ctx, -ctx->rot_speed);
	mlx_clear_window(ctx->inst, ctx->win);
	init_ray_casting(ctx);
	return (0);
}
