/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:30:06 by anomourn          #+#    #+#             */
/*   Updated: 2024/04/22 17:23:11 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sign(int sign)
{
	static unsigned char	c;
	static int				bit_i;

	c |= (sign == SIGUSR1);
	bit_i++;
	if (bit_i == 8)
	{
		if (c == 0)
			ft_printf("\n");
		else
			ft_printf("%c", c);
		bit_i = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, handle_sign);
		signal(SIGUSR2, handle_sign);
	}
	return (0);
}