/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:01:24 by beyarsla          #+#    #+#             */
/*   Updated: 2024/03/06 14:14:21 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	send_bit(int server_pid, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 7;
		while (j >= 0)
		{
			if ((str[i] >> j) & 1)
				kill(server_pid, SIGUSR2);
			else
				kill(server_pid, SIGUSR1);
			j--;
			usleep(100);
		}
		i++;
	}
}

static void	send_chr(int server_pid, char c)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if ((c >> j) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		j--;
		usleep(100);
	}
}

static void	send_string(char **str)
{
	int	server_pid;

	server_pid = ft_atoi(str[1]);
	if (server_pid < 0 && write(1, "ERROR: Wrong PID", 17))
		exit(0);
	send_bit(server_pid, str[2]);
	send_chr(server_pid, 0);
	send_chr(server_pid, 1);
	send_bit(server_pid, ft_itoa(getpid()));
	send_chr(server_pid, 0);
	send_chr(server_pid, 1);
}

static void	handle(int signo)
{
	if (signo == SIGUSR1 && write(1, "OKEY", 5))
		exit(0);
}

int	main(int argc, char **argv)
{
	signal(SIGUSR1, &handle);
	if (argc == 3)
	{
		send_string(argv);
	}
	ft_printf("Error: invalid arguments\n./client <PID> <Message>");
	return (0);
}
