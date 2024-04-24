/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:30:12 by anomourn          #+#    #+#             */
/*   Updated: 2024/04/24 16:18:45 by anomourn         ###   ########.fr       */
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
		if (c % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c >>= 1;
		usleep(100);
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
	//printf("PID : %i\n", pid);
	if (pid <= 0)
	{
		ft_printf("PID invalid\n");
		exit(EXIT_FAILURE);
	}
	while (argv[2][i])
		send_signal(pid, argv[2][i++]);
	return (0);
}
