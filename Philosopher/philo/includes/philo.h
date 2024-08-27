/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:03:21 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/27 12:53:47 by aluzingu         ###   ########.fr       */
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

typedef struct  s_programa
{
    int number;
    time_t time_to_die;
    time_t time_to_eat;
    time_t time_to_sleep;
    int must_eat_count;
    time_t start_time;
    bool stop;
    pthread_t		grim_reaper;
    pthread_mutex_t *forks_locks;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	stop_lock;
    struct s_philo  **philos;
}   t_programa;
 
typedef struct s_philo
{
    int position;
    int times_eaten;
    int fork_left;
    int fork_right;
    time_t last_eaten;

    pthread_mutex_t	eating;
    pthread_t   thread;
    struct s_programa *programa;
}   t_philo;

void    ft_putchar(char c);
void    ft_putstr(char *str);
time_t current_time(void);
int ft_atoi(char *str);
t_programa *ft_init_programa(int argc, char **argv);
void philosopher(t_programa *programa);
void    sim_start_delay(time_t start_time);
bool    has_simulation_stopped(t_programa *programa);
void	philo_us_sleep(t_programa *programa, time_t sleep_time);
void    *grim_reaper(void *arg);
void    print_status(t_philo *philo, char *status, bool died);
#endif