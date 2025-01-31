#include "../include/core.h"


unsigned int rgb_to_hex(char *color)
{
	char **token;
	unsigned int hexa;
	token = ft_split(color, ',');
    hexa = (ft_atoi(token[0]) << 16) | (ft_atoi(token[1]) << 8) | ft_atoi(token[2]);
	ft_free_split(token);
	return (hexa);
}