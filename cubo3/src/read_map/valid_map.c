#include "../include/core.h"

void	validate_direction(t_context *ctx, int i, int j, int di, int dj)
{
	int	valid;

	valid = 0;
	while (i >= 0 && j >= 0 && ctx->map.map[i] && ctx->map.map[i][j])
	{
		if (ctx->map.map[i][j] == '1')
		{
			valid = 1;
			break;
		}
		i += di;
		j += dj;
	}
	if (!valid)
		ft_exit_free(ctx, NULL, "Error\nInvalid map\n");
}

void	validate_walls(t_context *ctx, int i, int j)
{
	validate_direction(ctx, i, j + 1, 0, 1);
	validate_direction(ctx, i, j - 1, 0, -1);
	validate_direction(ctx, i + 1, j, 1, 0);
	validate_direction(ctx, i - 1, j, -1, 0);
}

void ft_valid_map(t_context *ctx)
{
    int i;
    int j;
    char c;
    int fond_pos_player;

    i = 0;
    fond_pos_player = 0;
    while (ctx->map.map[i])
    {
        j = 0;
        while (ctx->map.map[i][j])
        {
            c = ctx->map.map[i][j];
            if (c != '0' && c != '1' && c != ' ' && c != 'N' && c != 'S' && c != 'W' && c != 'E')
                ft_exit_free(ctx, NULL, "Error\nInvalid map\n");
            if (c != '1' && c != ' ')
                validate_walls(ctx, i, j);
            if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
                fond_pos_player = 1;
            j++;
        }
        i++;
    }
    if (!fond_pos_player)
        ft_exit_free(ctx, NULL, "Error\nInvalid map\n");
}