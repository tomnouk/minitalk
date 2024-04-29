/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:30:06 by anomourn          #+#    #+#             */
/*   Updated: 2024/04/29 16:49:17 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sig(int bit)
{
	static unsigned	c;
	static int		len;

	//c <<= 1;
	c |= bit == SIGUSR1;
	len++;
	// if (bit == SIGUSR1)
	// 	bit = 1;
	// else
	// 	bit = 0;
	//ft_printf("%c", bit == SIGUSR1 ? '1' : '0');
	if (len == 8)
	{
		ft_printf("%c", c);
		if (c == 0)
			ft_printf("\n");
		// else
		// {
		// 	if(kill(getppid(), SIGUSR2) == -1)
		// 		exit(EXIT_FAILURE);
		// }
		len = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction sig;
	
	sig = (struct sigaction){0};
	sig.sa_flags = SA_SIGINFO;
	sig.sa_handler = handle_sig;
	ft_printf("PID : %i\n", getpid());
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
