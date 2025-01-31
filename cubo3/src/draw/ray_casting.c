#include "../include/core.h"

void perform_dda(t_context *ctx, char *side)
{
    // Detecta a colisão com uma parede usando o algoritmo DDA
    while (ctx->colision == 0)
    {
        if (ctx->side_dist_x < ctx->side_dist_y)
        {
            ctx->side_dist_x += ctx->delta_dist_x;
            ctx->map_x += ctx->step_x;
            *side = 'x';
        }
        else
        {
            ctx->side_dist_y += ctx->delta_dist_y;
            ctx->map_y += ctx->step_y;
            *side = 'y';
        }
        if (ctx->map.map[ctx->map_y][ctx->map_x] == '1')
            ctx->colision = 1;
    }
}

void ray_casting(t_context *ctx, int x)
{
    char side;

    //Posicao do jogado no mundo 3D
    if (ctx->raydir_x < 0)
    {
        ctx->step_x = -1;
        ctx->side_dist_x = (ctx->pos_x - ctx->map_x) * ctx->delta_dist_x;
    }
    else
    {
        ctx->step_x = 1;
        ctx->side_dist_x = (ctx->map_x - ctx->pos_x + 1.0) * ctx->delta_dist_x;
    }
    if (ctx->raydir_y < 0)
    {
        ctx->step_y = -1;
        ctx->side_dist_y = (ctx->pos_y - ctx->map_y) * ctx->delta_dist_y;
    }
    else
    {
        ctx->step_y = 1;
        ctx->side_dist_y = (ctx->map_y - ctx->pos_y + 1.0) * ctx->delta_dist_y;
    }

    // Chama o algoritmo DDA
    perform_dda(ctx, &side);

    // Calcula a distância real ate a parede
    float perp_wall_dist;
    if (side == 'x')
        perp_wall_dist = (ctx->map_x - ctx->pos_x + (1 - ctx->step_x) / 2) / ctx->raydir_x;
    else
        perp_wall_dist = (ctx->map_y - ctx->pos_y + (1 - ctx->step_y) / 2) / ctx->raydir_y;

    // Calcula a altura da linha a ser desenhada e a posição da textura
    int line_height = (int)(HEIGHT / perp_wall_dist);
    int draw_start =  (HEIGHT - line_height) / 2;
    if (draw_start < 0)
        draw_start = 0;
    int draw_end = (line_height + HEIGHT) / 2;
    if (draw_end >= HEIGHT)
        draw_end = HEIGHT - 1;

    // Determina a posição da textura
    double wall_x;
    if (side == 'x')
        wall_x = ctx->pos_y + perp_wall_dist * ctx->raydir_y;
    else
        wall_x = ctx->pos_x + perp_wall_dist * ctx->raydir_x;
    
    wall_x -= floor(wall_x);
    int text_x = (int)(wall_x * (double)IMG_WIDTH);
    
    // Ajusta a textura de acordo com a direção do raio
    if ((side == 'x' && ctx->raydir_x > 0) || (side == 'y' && ctx->raydir_y < 0))
        text_x = IMG_WIDTH - text_x - 1;

    // Passo para a textura e posição inicial da textura
    double step = 1.0 * IMG_HEIGHT / line_height;
    double text_pos = (draw_start - HEIGHT / 2 + line_height / 2) * step;

    // Desenha a parede pixel a pixel
    int y = draw_start;
    int color;
    int text_y;
    while (y < draw_end)
    {
        text_y = (int)text_pos & (IMG_HEIGHT - 1);
        text_pos += step;
        color = 0;

        if (ctx->raydir_y < 0 && side == 'y')
            color = ctx->map.so[text_y * IMG_HEIGHT + text_x];
        else if (ctx->raydir_x < 0 && side == 'x')
            color = ctx->map.we[text_y * IMG_HEIGHT + text_x];
        else if (ctx->raydir_y > 0 && side == 'y')
            color = ctx->map.no[text_y * IMG_HEIGHT + text_x];
        else if (ctx->raydir_x > 0 && side == 'x')
            color = ctx->map.ea[text_y * IMG_HEIGHT + text_x];

        my_mlx_pixel_put(ctx, x, y, color);
        y++;
    }
}