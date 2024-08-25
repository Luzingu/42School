/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:03:21 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/25 04:43:48 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct  s_programa
{
    int number;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int times_to_eat;
    int good;
    int eat_count;
    long long start_time;
    int run;

    pthread_mutex_t *forks;
    
	pthread_mutex_t	m_eat_count;
	pthread_mutex_t	m_good;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_dead;
    pthread_t		monitor;
    
    int stop;
}   t_programa;
 
typedef struct s_philo
{
    int position;
    int times_eaten;
    long long last_eaten;
    long long limit_eat;

    pthread_mutex_t	m_eating;
    pthread_mutex_t *fork_right;
    pthread_mutex_t *fork_left;
    pthread_t   thread;
    struct s_programa *programa;
}   t_philo;

void    ft_putchar(char c);
void    ft_putstr(char *str);
long long current_time(void);
int ft_atoi(char *str);
void ft_init_programa(int argc, t_programa *programa, char **argv);
t_philo   *ft_init_philos(t_programa *programa);
void philosopher(t_programa *programa, t_philo *philos);
void *monitor(void *arg);
unsigned long	display_time(t_philo *philo);
unsigned long	ft_timestamp(void);
void	ft_usleep(t_programa *programa, int stop_ms);
int	check_good(t_programa *programa);
#endif