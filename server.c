/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:34:29 by beyarsla          #+#    #+#             */
/*   Updated: 2024/02/13 13:34:33 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_Printf/ft_printf.h"
#include "signal.h"
#include "unistd.h"

void handle(int signum)
{
	static char c;
	static int i = 64;
	
	if (signum == SIGUSR2)
 		c += i;
	i >>= 1;
	if (i == 0)
	{
		write(1,&c, 1);
		c = 0;
		i = 64;
	}
	
}	

int main()
{
	ft_printf("PID: %d\n",getpid());
	signal(SIGUSR2,handle);
	signal(SIGUSR1,handle);
	while(1)
		usleep(100);
}