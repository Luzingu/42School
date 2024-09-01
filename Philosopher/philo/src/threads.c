/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:21:32 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/31 03:43:06 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_philo		*philo;
	t_programa	*programa;

	philo = (t_philo *)arg;
	programa = philo->programa;
	if (get_number(programa) == 1)
		return (lone_philo_routime(philo));
	else if (philo->position % 2)
		philo_us_sleep(programa, get_time_to_eat(programa) / 50);
	while (!get_stop(programa) && !get_max_ate(programa))
	{
		philo_eat(philo);
		print_status(philo, "is sleeping...");
		philo_us_sleep(philo->programa, philo->programa->time_to_sleep);
		print_status(philo, "is thinking...");
	}
	return (NULL);
}

void	exit_threads(t_programa *programa)
{
	int	i;

	i = -1;
	while (++i < get_number(programa))
		pthread_join(programa->philos[i].thread, NULL);
	i = -1;
	while (++i < get_number(programa))
		pthread_mutex_destroy(&programa->forks_locks[i]);
	pthread_mutex_destroy(&programa->eating);
	pthread_mutex_destroy(&programa->write_lock);
	free(programa->philos);
	free(programa->forks_locks);
	free(programa);
}

void	philosopher(t_programa *programa)
{
	int	i;

	i = 0;
	programa->start_time = current_time_in_ms();
	while (i < get_number(programa))
	{
		programa->philos[i].last_eaten = 0;
		pthread_create(&programa->philos[i].thread, NULL,
			routine, &programa->philos[i]);
		i++;
	}
	philo_dead(programa, programa->philos);
	exit_threads(programa);
}
