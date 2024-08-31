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
	if (!philo->programa->stop && !philo->programa->max_ate)
	{
		printf("%ld - Philo %d %s\n", current_time(philo->programa), (philo->position + 1), status);
	}
	pthread_mutex_unlock(&philo->programa->write_lock);
}

void	*lone_philo_routime(t_philo *philo)
{
	pthread_mutex_lock(&philo->programa->forks_locks[philo->fork_right]);
	print_status(philo, "has taken a fork...");
	philo_us_sleep(philo->programa, philo->programa->time_to_die);
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

	while (!programa->max_ate)
	{
		i = -1;
		while (++i < programa->number && !programa->stop)
		{
			pthread_mutex_lock(&programa->eating);
			if (programa->time_to_die < (current_time(programa) - philo[i].last_eaten))
			{
				print_status(&philo[i], "died");
				programa->stop = 1;
			}
			pthread_mutex_unlock(&programa->eating);
		}
		if (programa->stop)
			break ;
		i = 0;
		while (programa->must_eat_count && i < programa->number
			&& philo[i].times_eaten >= programa->must_eat_count)
			i++;
		programa->max_ate = (i == programa->number);
	}
}
