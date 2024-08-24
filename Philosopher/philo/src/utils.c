/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:13:42 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/24 13:48:21 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long current_time(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}


unsigned long	ft_timestamp(void)
{
	struct timeval	timespamp;
	unsigned long	l;
	unsigned long	s;
	unsigned long	u;

	gettimeofday(&timespamp, NULL);
	s = (timespamp.tv_sec * 1000);
	u = (timespamp.tv_usec / 1000);
	l = s + u;
	return (l);
}

unsigned long	display_time(t_philo *philo)
{
	return (ft_timestamp() - philo->programa->start_time);
}

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