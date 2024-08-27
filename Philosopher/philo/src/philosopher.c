/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 08:00:44 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/27 12:54:13 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    print_status(t_philo *philo, char *status, bool died)
{
    time_t diff;
    
    pthread_mutex_lock(&philo->programa->write_lock);
    if (has_simulation_stopped(philo->programa) == true && died == false)
    {
        pthread_mutex_unlock(&philo->programa->write_lock);
        return ;
    }    
    diff = current_time() - philo->programa->start_time;

    printf("%ld - Philo %d %s \n", diff, (philo->position + 1), status);
    pthread_mutex_unlock(&philo->programa->write_lock);
}

void    *lone_philo_routime(t_philo *philo)
{
    pthread_mutex_lock(&philo->programa->forks_locks[philo->fork_right]);
    print_status(philo, "has taken a fork...", false);
    philo_us_sleep(philo->programa, philo->programa->time_to_die);
    print_status(philo, "died.", false);
    pthread_mutex_unlock(&philo->programa->forks_locks[philo->fork_right]);
    return (NULL);
}

void    thik_routime(t_philo *philo, bool silent)
{
    time_t  time_to_think;

    pthread_mutex_lock(&philo->eating);
        time_to_think = (philo->programa->time_to_die - (current_time() - philo->last_eaten) - philo->programa->time_to_eat) / 2;
    pthread_mutex_unlock(&philo->eating);
    if (time_to_think < 0)
        time_to_think = 0;
    if (time_to_think == 0 && silent == true)
        time_to_think = 1;
    if (time_to_think > 600)
        time_to_think = 200;
    if (silent == false)
        print_status(philo, "is thinking...", false);
    philo_us_sleep(philo->programa, time_to_think);
}

void    eat_sleep_routime(t_philo *philo)
{
    pthread_mutex_lock(&philo->programa->forks_locks[philo->fork_left]);
    print_status(philo, "has taken a fork...", false);
    pthread_mutex_lock(&philo->programa->forks_locks[philo->fork_right]);
    print_status(philo, "has taken a fork...", false);
    print_status(philo, "is eating...", false);
    pthread_mutex_lock(&philo->eating);
    philo->last_eaten = current_time();
    pthread_mutex_unlock(&philo->eating);
    philo_us_sleep(philo->programa, philo->programa->time_to_eat);
    if (has_simulation_stopped(philo->programa) == false)
    {
        pthread_mutex_lock(&philo->eating);
        philo->times_eaten++;
        pthread_mutex_unlock(&philo->eating);
    }
    print_status(philo, "is sleeping...", false);
    pthread_mutex_unlock(&philo->programa->forks_locks[philo->fork_left]);
    pthread_mutex_unlock(&philo->programa->forks_locks[philo->fork_right]);
    philo_us_sleep(philo->programa, philo->programa->time_to_sleep);
}

void    *philo_action(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    
    if (philo->programa->must_eat_count == 0)
        return (NULL);
    pthread_mutex_lock(&philo->eating);
    philo->last_eaten = philo->programa->start_time;
    pthread_mutex_unlock(&philo->eating);
    sim_start_delay(philo->programa->start_time);
    if (philo->programa->time_to_die == 0)
        return (NULL);
    if (philo->programa->number == 1)
        return lone_philo_routime(philo);
    else if (philo->position % 2 == 1)
        thik_routime(philo, true);
    while (has_simulation_stopped(philo->programa) == false)
    {
        eat_sleep_routime(philo);
        thik_routime(philo, false);
    }
    return (NULL);
}

void    philosopher(t_programa *programa)
{
    int i;

    programa->start_time = current_time() + (programa->number * 2 * 10);
    i = 0;
    while (i < programa->number)
    {
        pthread_create(&programa->philos[i]->thread, NULL, philo_action, programa->philos[i]);
        i++;
    }
    if (programa->number > 1)
        pthread_create(&programa->grim_reaper, NULL, grim_reaper, programa);
}