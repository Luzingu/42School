/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 08:30:34 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/30 22:04:47 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

time_t	current_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

time_t	current_time(t_programa *programa)
{
	return (current_time_in_ms() - programa->start_time);
}

void	philo_us_sleep(t_programa *programa, time_t sleep_time)
{
	time_t	start;

	start = current_time_in_ms();
	while (!programa->stop)
	{
		if (current_time_in_ms() - start >= sleep_time)
			break ;
		usleep(programa->number * 2);
	}
}
