#include "../include/core.h"

void	ft_read_map_date(t_context *ctx, int map_line, int map_height, int map_width, int first_map_line, char *file)
{
	int i;
	int j;
	int k;
	int fd;
	char *line;

	ctx->map.map = (char **)malloc(sizeof(char *) * (map_height + 1));
	if (!ctx->map.map)
		ft_exit(ctx, "Error\nMalloc error\n");
	i = 0;
	while (i < map_height)
	{
		ctx->map.map[i] = (char *)malloc(sizeof(char) * (map_width + 1));
		if (!ctx->map.map[i])
			ft_exit(ctx, "Error\nMalloc error\n");
		i++;
	}
	fd = open(file, O_RDONLY);
	i = 0;
	int n = 0;
	while ((line = get_next_line(fd)))
	{
		if (i >= first_map_line)
		{
			j = 0;
			while (j < ft_strlen(line))
			{
				ctx->map.map[n][j] = line[j];
				j++;
			}
			ctx->map.map[n][j] = '\0';
			n++;
		}
		ft_free((void **)&line);
		i++;
	}
	ctx->map.map[n] = NULL;
	close(fd);
}