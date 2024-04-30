/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:29:12 by anomourn          #+#    #+#             */
/*   Updated: 2024/04/30 15:30:35 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal_bonus(int pid, unsigned char c)
{
	int				i;

	i = 8;
	while (i > 0)
	{
		i--;
		if ((c >> i) % 2 == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
		else if (kill(pid, SIGUSR1) == -1)
			exit(EXIT_FAILURE);
		pause();
		usleep(42);
	}
}

void	nothing_bonus(int sig)
{
	(void)sig;
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	signal(SIGUSR1, nothing_bonus);
	signal(SIGUSR2, nothing_bonus);
	if (argc != 3)
	{
		ft_printf("wrong number of arg\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("PID invalid\n");
		exit(EXIT_FAILURE);
	}
	while (argv[2][i])
		send_signal_bonus(pid, argv[2][i++]);
	send_signal_bonus(pid, 0);
	ft_printf("Message received\n");
	return (0);
}