/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:01:14 by beyarsla          #+#    #+#             */
/*   Updated: 2024/03/06 16:00:44 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft/libft.h"
#include "minitalk.h"

static void	send_signal(char **str)
{
	int	i;
	int	j;
	int	pid;

	i = 0;
	pid = ft_atoi(str[1]);
	if (pid < 0 && write(1, "ERROR: Wrong PID", 17))
		exit(0);
	while (str[2][i])
	{
		j = 6;
		while (j >= 0)
		{
			if ((str[2][i] >> j) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
			j--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		send_signal(argv);
		return (0);
	}
	ft_printf("Error: invalid arguments\n./client <PID> <Message>");
	return (0);
}
