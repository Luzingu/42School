/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 04:54:41 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/30 22:03:22 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int ft_init_mutex(t_programa *programa)
{
    int i;

    if (!programa->forks_locks)
        return (0);

    i = 0;
    while (i < programa->number)
    {
        if (pthread_mutex_init(&programa->forks_locks[i], NULL))
            return (0);
        i++;
    }
    if (pthread_mutex_init(&programa->write_lock, NULL))
        return (0);
    if (pthread_mutex_init(&programa->eating, NULL))
        return (0);
    return (1);
}

int ft_init_philos(t_programa *programa)
{
    int i;

    if (!programa->philos)
        return (0);

    i = 0;
    while (i < programa->number)
    {
        programa->philos[i].position = i;
        programa->philos[i].times_eaten = 0;
        programa->philos[i].fork_left = i;
        programa->philos[i].fork_right = (i + 1) % programa->number;
        programa->philos[i].programa = programa;
        i++;
    }
    return (1);
}

int ft_init(t_programa *programa)
{
    if (!(programa->philos = (t_philo *)malloc(sizeof(t_philo) * programa->number)))
        return (0);
    if (!(programa->forks_locks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * programa->number)))
    {
        free(programa->philos);
        return (0);
    }
    if (!ft_init_mutex(programa))
    {
        free(programa->philos);
        free(programa->forks_locks);
        return (0);
    }
    if (!ft_init_philos(programa))
    {
        free(programa->philos);
        free(programa->forks_locks);
        return (0);
    }
    return (1);
}


t_programa *ft_init_programa(int argc, char **argv)
{
    t_programa  *programa;
    int i;

    programa = (t_programa *)malloc(sizeof(t_programa));
    if (!programa)
        return (NULL);
    i = 0;
    if(argc == 6)
        i = ft_atoi(argv[5]);
    programa->number = ft_atoi(argv[1]);
    programa->time_to_die = ft_atoi(argv[2]);
    programa->time_to_eat = ft_atoi(argv[3]);
    programa->time_to_sleep = ft_atoi(argv[4]);
    programa->must_eat_count = i;
    programa->stop = 0;
    programa->max_ate = 0;
    if (!ft_init(programa))
        return (NULL);
    return programa;
}