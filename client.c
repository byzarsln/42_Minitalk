/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:34:54 by beyarsla          #+#    #+#             */
/*   Updated: 2024/02/13 13:37:33 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "printf/ft_printf.h"
#include "signal.h"
#include "unistd.h"

void	send_signal(char **str)
{
	int	i;
	int	j;
	int	pid;

	i = 0;
	pid = ft_atoi(str[1]);
	if (pid < 0)
		return (0);
	while (str[i])
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
	}
	return (0);
}