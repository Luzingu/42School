/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 08:00:44 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/24 14:29:25 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    print_status(t_philo *philos, char *status)
{
    long long diff;

    diff = display_time(philos);
    printf("%lld - Philo %d %s \n", diff, philos->position, status);
}

void    *philo_action(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;

    while (1)
    {
        pthread_mutex_lock(philo->fork_left);
        print_status(philo, "has taken left fork");
        pthread_mutex_lock(philo->fork_right);
        print_status(philo, "has taken right fork");
        philo->last_eaten = current_time();
        philo->times_eaten++;
        print_status(philo, "is eating...");
        usleep(philo->programa->time_to_eat * 1000);
        
        pthread_mutex_unlock(philo->fork_left);
        pthread_mutex_unlock(philo->fork_right);

        print_status(philo, "is sleeping...");
        usleep(philo->programa->time_to_sleep * 1000);
        print_status(philo, "is thinking");
    }
    return (NULL);
}


void    philosopher(t_programa programa, t_philo *philos)
{
    int i;

    i = 0;
    while (i < programa.number)
    {
        pthread_create(&philos[i].thread, NULL, philo_action, &philos[i]);
		usleep(80);
        i++;
    }
}