/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 04:54:41 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/27 12:43:00 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

pthread_mutex_t *ft_init_forks(t_programa *programa)
{
    pthread_mutex_t *forks;
    int i;

    forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * programa->number);
    if (!forks)
        return (NULL);
    i = 0;
    while (i < programa->number)
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }
    return (forks);
}

t_philo    **ft_init_philos(t_programa *programa)
{
    t_philo **philos;
    int i;

    i = 0;
    philos = (t_philo **)malloc(sizeof(t_philo) * programa->number);
    if (!philos)
        return (NULL);
    while (i < programa->number)
    {
        philos[i] = (t_philo *)malloc(sizeof(t_philo) * 1);
        if (!philos[i])
            return (NULL);
        pthread_mutex_init(&philos[i]->eating, NULL);
        philos[i]->position = i;
        philos[i]->times_eaten = 0;
        philos[i]->fork_left = i;
        philos[i]->fork_right = (i + 1) % programa->number;
        if (i % 2 == 0)
        {
            philos[i]->fork_right = i;
            philos[i]->fork_left = (i + 1) % programa->number;
        }
        philos[i]->programa = programa;
        i++;
    }
    return (philos);
}

t_programa *ft_init_programa(int argc, char **argv)
{
    t_programa  *programa;
    int i;

    programa = (t_programa *)malloc(sizeof(t_programa) * 1);
    if (!programa)
        return (NULL);
    i = -1;
    if(argc == 6)
        i = ft_atoi(argv[5]);
    programa->number = ft_atoi(argv[1]);
    programa->time_to_die = ft_atoi(argv[2]);
    programa->time_to_eat = ft_atoi(argv[3]);
    programa->time_to_sleep = ft_atoi(argv[4]);
    programa->must_eat_count = i;
    programa->stop = false;
    programa->philos = ft_init_philos(programa);
    programa->forks_locks = ft_init_forks(programa);
    if(!programa->forks_locks)
        return (NULL);
    pthread_mutex_init(&programa->write_lock, NULL);
    pthread_mutex_init(&programa->stop_lock, NULL);
    return (programa);
}