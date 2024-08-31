/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:03:21 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/31 03:42:49 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct s_programa
{
	struct s_philo	*philos;
	time_t		time_to_die;
	time_t		time_to_eat;
	time_t		time_to_sleep;
	time_t		start_time;
	int		stop;
	int		max_ate;
	int		number;
	int		must_eat_count;
	pthread_t		grim_reaper;
	pthread_mutex_t	*forks_locks;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	eating;
}	t_programa;
 
typedef struct s_philo
{
	struct s_programa	*programa;
	int		position;
	int		times_eaten;
	int		fork_left;
	int		fork_right;
	time_t	last_eaten;
	pthread_t	thread;
}	t_philo;

int		ft_atoi(char *str);

time_t	current_time_in_ms(void);
time_t	current_time(t_programa *programa);
t_programa	*ft_init_programa(int argc, char **argv);

void    ft_putchar(char c);
void    ft_putstr(char *str);
void	philosopher(t_programa *programa);
void	philo_us_sleep(t_programa *programa, time_t sleep_time);
void    philo_eat(t_philo *philo);
void    print_status(t_philo *philo, char *status);
void    philo_dead(t_programa *programa, t_philo *philo);
void    *lone_philo_routime(t_philo *philo);

#endif
