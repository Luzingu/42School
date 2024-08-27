/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grim_reaper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:05:37 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/27 13:04:46 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    set_stop_state(t_programa *programa, bool state)
{
    pthread_mutex_lock(&programa->stop_lock);
        programa->stop = state;
    pthread_mutex_unlock(&programa->stop_lock);
}

bool    kill_philo(t_philo *philo)
{
    time_t  time; 

    time = current_time();
    if ((time - philo->last_eaten) >= philo->programa->time_to_die)
    {
        set_stop_state(philo->programa, true);
        print_status(philo, "died", true);
        pthread_mutex_unlock(&philo->eating);
        return (true);
    }
    return (false);
}

bool    end_condition_reached(t_programa *programa)
{
    int i;
    bool all_ate_enough;

    all_ate_enough = true;
    i = 0; 
    while (i < programa->number)
    {
        pthread_mutex_lock(&programa->philos[i]->eating);
        if (kill_philo(programa->philos[i]))
            return (true);
        if (programa->must_eat_count != -1)
        {
            if(programa->philos[i]->times_eaten < programa->must_eat_count)
                all_ate_enough = false;
        }
        pthread_mutex_unlock(&programa->philos[i]->eating);
        i++;
    }
    if (programa->must_eat_count != -1 && all_ate_enough == true)
    {
        set_stop_state(programa, true);
        return (true);
    }
    return (false);
}

void    *grim_reaper(void *arg)
{
    t_programa  *programa;

    programa = (t_programa *)arg;
    if (programa->must_eat_count == 0)
        return (NULL);
    set_stop_state(programa, false);
    sim_start_delay(programa->start_time);
    while(1)
    {
        if (end_condition_reached(programa) == true)
            return (NULL);
        usleep(1000);
    }
    return (NULL);
}