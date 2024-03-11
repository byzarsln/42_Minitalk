/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:12:19 by beyarsla          #+#    #+#             */
/*   Updated: 2024/03/06 16:01:01 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle(int signum)
{
	static char	c;
	static int	i = 64;

	if (signum == SIGUSR2)
		c += i;
	i >>= 1;
	if (i == 0)
	{
		write(1, &c, 1);
		c = 0;
		i = 64;
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR2, handle);
	signal(SIGUSR1, handle);
	while (1)
		usleep(100);
}
