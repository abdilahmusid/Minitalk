/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:35:43 by amousaid          #+#    #+#             */
/*   Updated: 2024/01/27 01:05:26 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <signal.h>

void	ft_send_bit(int pid, char *s)
{
	int	i;
	int	next;
	int	pid_check;

	i = 0;
	while (s[i])
	{
		next = 7;
		while (next >= 0)
		{
			if ((s[i] >> next) & 1)
				pid_check = kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(9);
			next--;
		}
		i++;
	}
	if (pid_check == -1)
		ft_printf("[PID IS WRONG]\n");
}

int	main(int argc, char **argv)
{
	char	*str;
	int		pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		ft_send_bit(pid, str);
	}
	else if (argc > 3)
		ft_printf("You are write more than 2 argument");
	else
		ft_printf("You are write less than 2 argument");
}
