/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 04:54:41 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/24 14:26:44 by aluzingu         ###   ########.fr       */
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
    programa->run = 1;
    programa->start_time = ft_timestamp();
    programa->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * programa->number);
    pthread_mutex_init(&programa->meal_check, NULL);
    if(!programa->forks)
    {
        ft_putstr("Error Program.");
        exit(0);
    } 
    i = -1;
    while (++i < programa->number)
        pthread_mutex_init(&programa->forks[i], NULL);
}

t_philo   *ft_init_philos(t_programa programa)
{
    t_philo *philos;
    int i;

    philos = (t_philo *)malloc(sizeof(t_philo) * programa.number);
    i = 0;
    while (i < programa.number)
    {
        philos[i].position = (i + 1);
        philos[i].times_eaten = 0;
        philos[i].last_eaten = programa.start_time;
        philos[i].fork_left = &programa.forks[i];

        if (i == (programa.number - 1))
            philos[i].fork_right = &programa.forks[0];
        else
            philos[i].fork_right = &programa.forks[i + 1];
        philos[i].programa = &programa;
        i++;
    }
    return (philos);
}