#include "../include/core.h"

void	ft_read_file(char *file, t_context *ctx)
{
	int fd;
	char *line;
	int map_line;

	int map_height;
	int map_width;
	int first_map_line;

	fd = ft_is_valid_file(file, ".cub");
	if (fd == -1)
		ft_exit(ctx, "Error\nInvalid file\n");
	map_line = 0;
	map_height = 0;
	map_width = 0;
	int i = 0;
	first_map_line = 0;
	while ((line = get_next_line(fd)))
	{
		if (!map_line)
			ft_read_data(ctx, line, &map_line);
		else
		{
			if (!first_map_line)
				first_map_line = i;
			map_height++;
			if(map_width < ft_strlen(line))
				map_width = ft_strlen(line);
		}
		ft_free((void **)&line);
		i++;
	}
	close(fd);
	ft_read_map_date(ctx, map_line, map_height, map_width, first_map_line, file);
	ft_valid_map(ctx);
}