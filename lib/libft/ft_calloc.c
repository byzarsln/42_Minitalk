/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:14:14 by beyarsla          #+#    #+#             */
/*   Updated: 2024/03/05 16:14:17 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	size_t	total_size;
	void	*memory;
	char	*ptr;
	size_t	i;

	total_size = num_elements * element_size;
	memory = malloc(total_size);
	if (!memory)
		return (0);
	else
	{
		ptr = (char *)memory;
		i = 0;
		while (i < total_size)
		{
			ptr[i] = 0;
			i++;
		}
	}
	return (memory);
}
