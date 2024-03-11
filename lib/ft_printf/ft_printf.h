/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:13:55 by beyarsla          #+#    #+#             */
/*   Updated: 2024/03/05 16:13:58 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_putchar(char c);
int	ft_putstr(char *c);
int	ft_putnbr(int c);
int	ft_uns(unsigned int a);
int	ft_printf(const char *str, ...);
int	ft_hex(unsigned int h, int b);
int	ft_ptr(unsigned long h, int b);

#endif