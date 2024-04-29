/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:30:12 by anomourn          #+#    #+#             */
/*   Updated: 2024/04/29 16:51:15 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, unsigned char c)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		i--;
		c >>= 1;
		if (c % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		//pause();
	}
}


int		main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
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
	write(1, "Message sent\n", 13);
	return (0);
}
