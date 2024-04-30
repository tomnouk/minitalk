/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:26:24 by anomourn          #+#    #+#             */
/*   Updated: 2024/04/30 15:31:13 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "./printf/ft_printf.h"

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <string.h>

void	handle_sig(int bit, siginfo_t *info, void *context);
void	send_signal(int pid, unsigned char c);

void	handle_sig_bonus(int bit, siginfo_t *info, void *context);
void	send_signal_bonus(int pid, unsigned char c);

#endif