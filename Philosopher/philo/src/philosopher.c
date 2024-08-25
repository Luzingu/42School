/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 08:00:44 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/25 05:08:11 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    print_status(t_philo *philos, char *status)
{
    long long diff;
    
    pthread_mutex_lock(&philos->programa->m_print);
    if (philos->programa->good == 1)
    {
        diff = current_time() - philos->programa->start_time; 
        printf("%lld - Philo %d %s \n", diff, philos->position, status);
    }
    pthread_mutex_unlock(&philos->programa->m_print);
}

void    *philo_action(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    
    while (1)
    {
        if (philo->programa->times_to_eat != -1 && philo->times_eaten == philo->programa->times_to_eat)
            return (NULL);
        if (check_good(philo->programa))
			return (NULL);
        pthread_mutex_lock(philo->fork_left);
        print_status(philo, "has taken left fork");
        pthread_mutex_lock(philo->fork_right);
        print_status(philo, "has taken right fork");
        philo->last_eaten = current_time();
        philo->limit_eat = philo->last_eaten + philo->programa->time_to_die;
        philo->times_eaten++;
        print_status(philo, "is eating...");
        ft_usleep(philo->programa, philo->programa->time_to_eat);
        pthread_mutex_unlock(philo->fork_left);
        pthread_mutex_unlock(philo->fork_right);

        if(philo->programa->times_to_eat != -1)
        {
            pthread_mutex_lock(&philo->programa->m_eat_count);
                philo->times_eaten++;
                philo->programa->eat_count++;
            pthread_mutex_lock(&philo->programa->m_eat_count);
        }
        print_status(philo, "is sleeping...");
        ft_usleep(philo->programa, philo->programa->time_to_sleep);
        if (check_good(philo->programa))
			return (NULL);
        print_status(philo, "is thinking");
    }
    return (NULL);
}

void    philosopher(t_programa *programa, t_philo *philos)
{
    int i;

    pthread_create(&programa->monitor, NULL, monitor, philos);
    i = 0;
    while (i < programa->number)
    {
        pthread_create(&philos[i].thread, NULL, philo_action, &philos[i]);
        i++;
    }
    i = 0;
    while (i < programa->number)
    {
        pthread_join(philos[i].thread, NULL);
        i++;
    }
     pthread_join(programa->monitor, NULL);
}