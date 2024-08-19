/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:17:35 by aluzingu          #+#    #+#             */
/*   Updated: 2024/08/14 18:17:37 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void	handle_signal(int sinal, siginfo_t *info, void *contexto)
{
	static char	character;
	static int	contador;
	int			bit;

	(void)contexto;
	(void)info;
	if (sinal == SIGUSR1)
		bit = 1;
	else if (sinal == SIGUSR2)
		bit = 0;
	character |= (bit << (7 - contador));
	if (contador == 7)
	{
		if (character == '\0')
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
			ft_printf("Mensagem Recebida de %d\n", info->si_pid);
		}
		else
			write(1, &character, 1);
		character = 0;
		contador = 0;
	}
	else
	    contador++;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	ft_printf("PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
