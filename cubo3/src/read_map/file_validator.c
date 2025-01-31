
#include "../include/core.h"

int ft_is_valid_file(char *file, char *pre_format)
{
    int fd;
    int len;

    if (!file || !pre_format)
        return (-1);
    len = ft_strlen(file);
    if (len < 4 || ft_cmp(&file[len - 4], pre_format))
        return (-1);
    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (-1);
    return (fd);
}

int valid_rgb(char *str)
{
    char **token;
    int i;
    int val;

    token = ft_split(str, ',');
    if (!token || numb_split(token) != 3)
        return (ft_free_split(token), 0);
    i = 0;
    while (token[i])
    {
        val = ft_atoi(token[i]);
        if (val < 0 || val > 255)
        {
            ft_free_split(token);
            return (0);
        }
        i++;
    }
    ft_free_split(token);
    return (1);
}