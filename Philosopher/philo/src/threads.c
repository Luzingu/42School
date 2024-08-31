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
	if (programa->number == 1)
		return (lone_philo_routime(philo));
	if (philo->position % 2 && programa->number > 1)
		philo_us_sleep(programa, programa->time_to_eat / 50);
	while (!programa->stop && !programa->max_ate)
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
	while (++i < programa->number)
		pthread_join(programa->philos[i].thread, NULL);
	i = -1;
	while (++i < programa->number)
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
	while (i < programa->number)
	{
		programa->philos[i].last_eaten = 0;
		pthread_create(&programa->philos[i].thread, NULL,
			routine, &programa->philos[i]);
		i++;
	}
	philo_dead(programa, programa->philos);
	exit_threads(programa);
}
