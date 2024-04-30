/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:30:06 by anomourn          #+#    #+#             */
/*   Updated: 2024/04/30 11:31:54 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sig(int bit, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int	len;

	(void)context;
	c <<= 1;
	c |= bit == SIGUSR1;
	len++;
	//ft_printf("%c", bit == SIGUSR1 ? '1' : '0');
	if (len == 8)
	{
		ft_printf("%c", c);
		if (c == 0)
			ft_printf("\n");
		len = 0;
		c = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		exit(EXIT_FAILURE);
}

int	main(void)
{
	struct sigaction sig;
	
	ft_printf("PID : %i\n", getpid());
	sig.sa_sigaction = handle_sig;
	sigemptyset(&sig.sa_mask);
	//sig = (struct sigaction){0};
	sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sig, NULL) == -1)
		exit(EXIT_FAILURE);
	while (1)
		pause();
	return (0);
}
