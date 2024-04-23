/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:30:06 by anomourn          #+#    #+#             */
/*   Updated: 2024/04/23 15:51:26 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sig(int bit)
{
	static unsigned char c;
	static int len;

	c <<= 1;
	c |= bit == SIGUSR2;
	len++;
	if (len == 8)
	{
		ft_printf("%c", c);
		if (c == 0)
		{
			if(kill(getppid(), SIGUSR2) == -1)
				exit(EXIT_FAILURE);
			ft_printf("\n");
		}
		else
		{
			if(kill(getppid(), SIGUSR1) == -1)
				exit(EXIT_FAILURE);
		}
		len = 0;
	}
}

int	main(void)
{
	ft_printf("PID : %i\n", getpid());
	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	while (1)
	{
		pause();
	}
	return (0);
}
