/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:13:42 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/25 04:45:03 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long current_time(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
 
int	check_good(t_programa *programa)
{
	pthread_mutex_lock(&programa->m_good);
	if (!programa->good)
	{
		pthread_mutex_unlock(&programa->m_good);
		return (1);
	}
	pthread_mutex_unlock(&programa->m_good);
	return (0);
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

void	ft_usleep(t_programa *programa, int stop_ms)
{
	long long	end_ms;

	end_ms = current_time() + stop_ms;
	while (current_time() < end_ms)
	{
		pthread_mutex_lock(&programa->m_good);
		if (programa->good != 1)
		{
			pthread_mutex_unlock(&programa->m_good);
			return ;
		}
		pthread_mutex_unlock(&programa->m_good);
		usleep(100);
	}
}