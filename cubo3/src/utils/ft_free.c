#include "../include/core.h"


void    ft_free(void **ptr)
{
    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL;
    }
}

void    ft_free_split(char **argv)
{
    int i;

    if (argv == NULL)
        return ;
    i = 0;
    while (argv[i])
    {
        ft_free((void **)&argv[i]);
        i++;
    }
    ft_free((void **)&argv);
}


void ft_free_ctx(t_context *ctx)
{
    /*ft_free((void **)&ctx->map.no);
    ft_free((void **)&ctx->map.so);
    ft_free((void **)&ctx->map.we);
    ft_free((void **)&ctx->map.ea);*/

    //ft_free((void **)&ctx->map.f);
    //ft_free((void **)&ctx->map.c);
    mlx_destroy_image(ctx->inst, ctx->img);
    mlx_destroy_window(ctx->inst, ctx->win);
    mlx_destroy_display(ctx->inst);
    //ft_free((void **)&ctx->inst);
    //ft_free((void **)&ctx->win);
    ft_free((void **)&ctx->img);
    ft_free((void **)&ctx);
}


void ft_exit(t_context *ctx,  char *str)
{
	if(str)
		ft_putstr_fd(str, 2);
	ft_free_ctx(ctx);
	exit(0);
}

void ft_exit_free(t_context *ctx, char *str_free, char *out)
{
	ft_free((void **)&str_free);
	ft_free((void **)&ctx->free.str1);
	ft_free((void **)&ctx->free.str2);
	ft_free((void **)&ctx->free.str3);
	ft_free_split(ctx->free.mtx1);
	ft_free_split(ctx->free.mtx2);
	ft_free_split(ctx->free.mtx3);
	ft_exit(ctx, out);
}