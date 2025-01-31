#include "../include/core.h"

void	set_player_direction_ns(t_context *ctx, char dir)
{
	if (dir == 'N')
	{
		ctx->dir_x = 0;
		ctx->dir_y = -1;
		ctx->plane_x = FOV;
		ctx->plane_y = 0;
	}
	else if (dir == 'S')
	{
		ctx->dir_x = 0;
		ctx->dir_y = 1;
		ctx->plane_x = -FOV;
		ctx->plane_y = 0;
	}
}

void	set_player_direction_ew(t_context *ctx, char dir)
{
	if (dir == 'E')
	{
		ctx->dir_x = 1;
		ctx->dir_y = 0;
		ctx->plane_x = 0;
		ctx->plane_y = FOV;
	}
	else if (dir == 'W')
	{
		ctx->dir_x = -1;
		ctx->dir_y = 0;
		ctx->plane_x = 0;
		ctx->plane_y = -FOV;
	}
}

void	set_player_position(t_context *ctx, int i, int n)
{
	ctx->pos_x = n + 0.5;
	ctx->pos_y = i + 0.5;
	set_player_direction_ns(ctx, ctx->map.map[i][n]);
	set_player_direction_ew(ctx, ctx->map.map[i][n]);
	ctx->map.map[i][n] = '0';
}

void	define_player_position(t_context *ctx)
{
	int	i;
	int	n;
	char	dir;

	i = 0;
	while (ctx->map.map[i])
	{
		n = 0;
		while (ctx->map.map[i][n])
		{
			dir = ctx->map.map[i][n];
			if (dir == 'N' || dir == 'E' || dir == 'S' || dir == 'W')
			{
				set_player_position(ctx, i, n);
				return ;
			}
			n++;
		}
		i++;
	}
}