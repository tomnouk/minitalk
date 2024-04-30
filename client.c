/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:30:12 by anomourn          #+#    #+#             */
/*   Updated: 2024/04/30 12:24:13 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, unsigned char c)
{
	int	i;
	unsigned char	tmp;

	i = 8;
	while (i > 0)
	{
		i--;
		tmp = c >> i;
		if (tmp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(42);
	}
}

void	nothing(int sig)
{
	(void)sig;
}


int		main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	signal(SIGUSR1, nothing);
	signal(SIGUSR2, nothing);
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
		send_signal(pid, argv[2][i++]);
	send_signal(pid, 0);
	ft_printf("Message received\n");
	return (0);
}
