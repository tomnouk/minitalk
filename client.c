/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:30:12 by anomourn          #+#    #+#             */
/*   Updated: 2024/04/22 17:22:53 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, unsigned int c)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		i--;
		c >>= i;
		if (c % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

void	handle_mess()
{
	ft_printf("message received\n");
	exit(0);
}

int main(int argc, char **argv)
{
	int	s_pid;
	int	i;

	if (argc != 3)
		return (ft_printf("wrong number of arg\n"));
	signal(SIGUSR1, handle_mess);
	s_pid = ft_atoi(argv[1]);
	i = 0;
	send_signal(s_pid, getpid());
	while (argv[2][i])
	{
		send_signal(s_pid, argv[2][i]);
		i++;
	}
	send_signal(s_pid, 0);
	pause();
	return (0);
}
