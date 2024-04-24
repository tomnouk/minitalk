/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:30:06 by anomourn          #+#    #+#             */
/*   Updated: 2024/04/24 16:19:56 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sig(int bit)
{
	static char c;
	static int len;

	c <<= 1;
	c |= bit == SIGUSR1;
	len++;
	//ft_printf("%c", bit == SIGUSR1 ? '1' : '0');
	if (len == 8)
	{
		ft_printf("%c", c);
		if (c == 0)
		{
			// if(kill(getppid(), SIGUSR1) == -1)
			// 	exit(EXIT_FAILURE);
			ft_printf("\n");
		}
		// else
		// {
		// 	if(kill(getppid(), SIGUSR2) == -1)
		// 		exit(EXIT_FAILURE);
		// }
		len = 0;
	}
}

int	main(void)
{
	struct sigaction sig;
	
	sig = (struct sigaction){0};
	sig.sa_handler = handle_sig;
	sig.sa_flags = SA_SIGINFO;
	ft_printf("PID : %i\n", getpid());
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
