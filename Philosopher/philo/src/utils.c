/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:13:42 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/27 11:05:17 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    while (*str)
    {
        ft_putchar(*str);
        str++;   
    }
}

int ft_atoi(char *str)
{
    int i;
    int number;

    i = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    number = 0;
    while (str[i])
    {
        if(str[i] >= 48 && str[i] <= 57)
            number = number * 10 + (str[i] - 48);
        else
            return (0);
        i++;
    }
    return (number);
}