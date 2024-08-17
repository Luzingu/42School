/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_sinal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:53:15 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/15 17:53:16 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

int	is_number(char *argv)
{
	int	i;

	i = 0;
	if ((argv[i] == '+' || argv[i] == '-') && argv[i + 1] != '\0')
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

void	send_bits(pid_t pid, unsigned char c)
{
	int	bit;
	int	i;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(60);
	}
}

void	handle_signal(int sinal)
{
	if (sinal == SIGUSR1)
		ft_printf("SERVER: A tua mensagem foi recebida com sucesso.");
}

int	correct_input(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Usage: ./client PID message");
		return (0);
	}
	else
	{
		if (!is_number(argv[1]))
		{
			ft_printf("PID Invalid");
			return (0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				pid;
	int					i;

	sa.sa_handler = handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	if (correct_input(argc, argv))
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i])
		{
			send_bits(pid, argv[2][i]);
			i++;
		}
		send_bits(pid, '\0');
	}
	return (0);
}
