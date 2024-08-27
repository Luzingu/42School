/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:05:01 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/27 11:32:34 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int ft_check_input(int argc, char **argv)
{
    int i;

    if (!(argc == 5 || argc == 6))
    {
        ft_putstr("Usage: ./philo numb_philo time_to_die time_to_eat time_to_sleap times_to_eat\n");
        return (0);
    }
    i = 1;
    while (argv[i])
    {
        if (!ft_atoi(argv[i]))
        {
            ft_putstr("Invalid Input!\n");
            return (0);
        }  
        i++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    t_programa  *programa;

    programa = NULL;
    if(ft_check_input(argc, argv))
    {  
        programa = ft_init_programa(argc, argv); 
        philosopher(programa);

        int i = 0;
        while (i < programa->number)
        {
            pthread_join(programa->philos[i]->thread, NULL);
            i++;
        }
        if (programa->number > 1)
            pthread_join(programa->grim_reaper, NULL);
                        
    }
    return (0);
}