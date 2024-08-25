/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 04:54:41 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/25 04:44:58 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void ft_init_programa(int argc, t_programa *programa, char **argv)
{
    int i;

    i = -1;
    if(argc == 6)
        i = ft_atoi(argv[5]);
    programa->number = ft_atoi(argv[1]);
    programa->time_to_die = ft_atoi(argv[2]);
    programa->time_to_eat = ft_atoi(argv[3]);
    programa->time_to_sleep = ft_atoi(argv[4]);
    programa->times_to_eat = i;
    programa->stop = 0;
    programa->eat_count = 0;
    programa->good = 1;
    programa->start_time = current_time();
    programa->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * programa->number);
    if(!programa->forks)
    {
        ft_putstr("Error Program.");
        exit(0);
    } 
    i = -1;
    while (++i < programa->number)
        pthread_mutex_init(&programa->forks[i], NULL);
	pthread_mutex_init(&programa->m_good, NULL); 
	pthread_mutex_init(&programa->m_eat_count, NULL);
	pthread_mutex_init(&programa->m_print, NULL);
}

void    init_philo(t_philo **philos, t_programa *programa, int i)
{
    t_philo *p;

    p = *philos;
    while (i < programa->number)
    {
        p[i].position = (i + 1);
        p[i].times_eaten = 0;
        p[i].last_eaten = programa->start_time;
        p[i].fork_left = &programa->forks[i];
        p[i].limit_eat = programa->start_time + programa->time_to_die;
        if (i == (programa->number - 1))
            p[i].fork_right = &programa->forks[0];
        else
            p[i].fork_right = &programa->forks[i + 1];
        p[i].programa = programa;
        i += 2;
    }
}

t_philo   *ft_init_philos(t_programa *programa)
{
    t_philo *philos;

    philos = (t_philo *)malloc(sizeof(t_philo) * programa->number);
    init_philo(&philos, programa, 0);
    ft_usleep(programa, 10);
    init_philo(&philos, programa, 1);
    return (philos);
}