/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:21:32 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/30 22:01:40 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    *routime(void *arg)
{
    t_philo *philo;
    t_programa *programa;

    philo = (t_philo *)arg;
    programa = philo->programa;

    if(programa->number == 1)
        return lone_philo_routime(philo);
    if (philo->position % 2 && programa->number > 1)
        philo_us_sleep(programa, programa->time_to_eat / 50); 
    while (!programa->stop && !programa->max_ate)
    {
        philo_eat(philo);
        print_status(philo, "is sleeping...", false);
        philo_us_sleep(philo->programa, philo->programa->time_to_sleep);
        print_status(philo, "is thinking...", false);
    }
    return (NULL);
}

void    exit_threads(t_programa *programa)
{
    int i;
    
    i = -1;
    while (++i < programa->number)
        pthread_join(programa->philos[i].thread, NULL);
    i = -1; 
    while(++i < programa->number)
        pthread_mutex_destroy(&programa->forks_locks[i]); 
    pthread_mutex_destroy(&programa->eating);
    pthread_mutex_destroy(&programa->write_lock);
    free(programa->philos);
    free(programa->forks_locks);
    free(programa);
}

void    philosopher(t_programa *programa)
{
    int i;
    i = 0;

    programa->start_time = current_time_in_ms();
    while (i < programa->number)
    {
        programa->philos[i].last_eaten = current_time_in_ms();
        pthread_create(&programa->philos[i].thread, NULL, routime, &programa->philos[i]);
        i++;
    }
    philo_dead(programa, programa->philos);
    pthread_mutex_unlock(&programa->write_lock);
    exit_threads(programa);
}