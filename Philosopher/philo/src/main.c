/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:05:01 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/30 22:00:05 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_check_input(int argc, char **argv)
{
	int	i;

	if (!(argc == 5 || argc == 6))
	{
		ft_putstr("Usage: ./philo numb_philo time_to_die");
		ft_putstr("time_to_eat time_to_sleep times_to_eat\n");
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

int	main(int argc, char **argv)
{
	t_programa	*programa;

	programa = NULL;
	if (ft_check_input(argc, argv))
	{
		programa = ft_init_programa(argc, argv);
		if (!programa)
			printf("Init Error\n");
		else
			philosopher(programa);
	}
	return (0);
}
