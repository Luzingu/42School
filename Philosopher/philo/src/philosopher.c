/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 08:00:44 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/31 03:42:22 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->programa->write_lock);
	if (!get_stop(philo->programa) && !get_max_ate(philo->programa))
	{
		printf("%ld - Philo %d %s\n", current_time(philo->programa),
			(philo->position + 1), status);
	}
	pthread_mutex_unlock(&philo->programa->write_lock);
}

void	*lone_philo_routime(t_philo *philo)
{
	pthread_mutex_lock(&philo->programa->forks_locks[philo->fork_right]);
	print_status(philo, "has taken a fork...");
	philo_us_sleep(philo->programa, get_time_to_die(philo->programa));
	pthread_mutex_unlock(&philo->programa->forks_locks[philo->fork_right]);
	return (NULL);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->programa->forks_locks[philo->fork_left]);
	print_status(philo, "has taken a fork...");
	pthread_mutex_lock(&philo->programa->forks_locks[philo->fork_right]);
	print_status(philo, "has taken a fork...");
	pthread_mutex_lock(&philo->programa->eating);
	print_status(philo, "is eating...");
	philo->last_eaten = current_time(philo->programa);
	pthread_mutex_unlock(&philo->programa->eating);
	philo_us_sleep(philo->programa, philo->programa->time_to_eat);
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->programa->forks_locks[philo->fork_left]);
	pthread_mutex_unlock(&philo->programa->forks_locks[philo->fork_right]);
}

void	philo_dead(t_programa *programa, t_philo *philo)
{
	int	i;

	while (!get_max_ate(programa))
	{
		i = -1;
		while (++i < get_number(programa) && !get_stop(programa))
		{
			pthread_mutex_lock(&programa->eating);
			if (get_time_to_die(programa)
				< (current_time(programa) - philo[i].last_eaten))
			{
				print_status(&philo[i], "died");
				pthread_mutex_lock(&programa->get_value);
				programa->stop = 1;
				pthread_mutex_unlock(&programa->get_value);
			}
			pthread_mutex_unlock(&programa->eating);
		}
		if (get_stop(programa))
			break ;
		i = 0;
		while (get_must_eat_count(programa) && i < get_number(programa)
			&& philo[i].times_eaten >= get_must_eat_count(programa))
			i++;
		programa->max_ate = (i == get_number(programa));
	}
}
