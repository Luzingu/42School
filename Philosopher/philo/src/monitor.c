/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:14:25 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/25 05:03:00 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	monitor_eat(t_programa *programa)
{ 
	pthread_mutex_lock(&programa->m_eat_count); 
	if (programa->eat_count >= programa->number * programa->times_to_eat
		&& programa->times_to_eat != -1)
	{
		pthread_mutex_lock(&programa->m_good);
		programa->good = 0;
		pthread_mutex_unlock(&programa->m_good);
		pthread_mutex_unlock(&programa->m_eat_count);
		return (1);
	}
	pthread_mutex_unlock(&programa->m_eat_count);
	return (0);
}

int	monitor_life(t_philo *philos, int i)
{
	t_programa *programa;

	programa = philos->programa;
		
	if (current_time() > philos[i].limit_eat)
	{
		pthread_mutex_lock(&programa->m_print);
		pthread_mutex_lock(&programa->m_good);
		programa->good = 0;
		pthread_mutex_unlock(&programa->m_good); 
		printf("%lld %d died\n", current_time() - programa->start_time, i + 1);
		pthread_mutex_unlock(&programa->m_print);
		return (1);
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_programa		*programa;
	t_philo	*philos;
	int			i;

	philos = (t_philo *)arg;
	programa = philos->programa;
	while (1)
	{
		i = -1;
		while (++i < programa->number)
		{
			printf("Monitor checking philo %d at time %lld\n", (i + 1), current_time() - programa->start_time);
			pthread_mutex_lock(&philos[i].m_eating);
			if (monitor_life(philos, i) || monitor_eat(programa))
			{
				pthread_mutex_unlock(&philos[i].m_eating);
				return (NULL);
			}
			pthread_mutex_unlock(&philos[i].m_eating);
		}
		usleep(500);
	}
}