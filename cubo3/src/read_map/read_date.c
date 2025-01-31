#include "../include/core.h"

int ft_fill_img_text(t_context *ctx, char *orientation, char *img)
{
	void	*img_ptr;
	int 	fd;

	fd = ft_is_valid_file(img, ".xpm");
	if (fd == -1)
		return (0);
	close(fd);
	img_ptr = mlx_xpm_file_to_image(ctx->inst, img, &ctx->width_img, &ctx->height_img);
	if(!ft_cmp("NO", orientation) && ctx->map.no == 0)
		ctx->map.no = (int *)mlx_get_data_addr(img_ptr, &ctx->bpp, &ctx->size_line, &ctx->endian);
	else if(!ft_cmp("SO", orientation) && ctx->map.so == 0)
		ctx->map.so = (int *)mlx_get_data_addr(img_ptr, &ctx->bpp, &ctx->size_line, &ctx->endian);
	else if(!ft_cmp("WE", orientation) && ctx->map.we == 0)
		ctx->map.we = (int *)mlx_get_data_addr(img_ptr, &ctx->bpp, &ctx->size_line, &ctx->endian);
	else if(!ft_cmp("EA", orientation) && ctx->map.ea == 0)
		ctx->map.ea = (int *)mlx_get_data_addr(img_ptr, &ctx->bpp, &ctx->size_line, &ctx->endian);
	else
	{
		if (img_ptr)
    		mlx_destroy_image(ctx->inst, img_ptr);
		return (0);
	}
	return (1);
}

int fill_F_C(t_context *ctx, char *str, char *rgb)
{
	if (!valid_rgb(rgb))
		return (0);
	if (!ft_cmp("F", str) && !ctx->map.f)
		ctx->map.f = ft_strdup(rgb);
	else if (!ft_cmp("C", str) && !ctx->map.c)
		ctx->map.c = ft_strdup(rgb);
	else
		return (0);
	return (1);
}

void ft_read_data(t_context *ctx, char *line, int *map_line)
{

	ctx->free.str1 = ft_strtrim(line, " ");
	ctx->free.mtx1 = ft_split(ctx->free.str1, ' ');
	if (numb_split(ctx->free.mtx1) != 2)
		ft_exit_free(ctx, line, "Error\nInvalid data\n");
	if(!ft_cmp("NO", ctx->free.mtx1[0]) || !ft_cmp("SO", ctx->free.mtx1[0]) || !ft_cmp("WE", ctx->free.mtx1[0]) || !ft_cmp("EA", ctx->free.mtx1[0]))
	{
		if (!ft_fill_img_text(ctx, ctx->free.mtx1[0], ctx->free.mtx1[1]))
			ft_exit_free(ctx, line, "Error\nInvalid texture\n");
	}
	else if(ctx->free.mtx1[0][0] == 'F' || ctx->free.mtx1[0][0] == 'C')
	{
		if (!fill_F_C(ctx, ctx->free.mtx1[0], ctx->free.mtx1[1]))
			ft_exit_free(ctx, line, "Error\nInvalid color\n");
	}
	if (ctx->map.no && ctx->map.so && ctx->map.we && ctx->map.ea && ctx->map.f && ctx->map.c)
		*map_line = 1;
	ft_free((void **)&ctx->free.str1);
	ft_free_split(ctx->free.mtx1);
}