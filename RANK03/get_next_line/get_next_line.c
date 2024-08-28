#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif



char	*get_next_line(int fd)
{
	static char read_tmp[BUFFER_SIZE];
	char	*line;
	static int lido, pos;
	int	i;
	
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line = malloc(7000000))
		return (NULL);
	while (1)
	{
		if (pos >= lido)
		{
			lido = read(fd, read_tmp, BUFFER_SIZE);
			if(lido <= 0)
				break;
			pos = 0;
		}
		line[i++] = read_tmp[pos++];
		if(line[i - 1] == '\n')
			break;
	}
	line[i] = '\0';
	if (i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
