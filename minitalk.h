/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:26:24 by anomourn          #+#    #+#             */
/*   Updated: 2024/04/22 17:21:09 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "./printf/ft_printf.h"

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void	send_signal(int pid, unsigned int c);
void    handle_sign(int sign);

#endif