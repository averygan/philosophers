/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:45:46 by agan              #+#    #+#             */
/*   Updated: 2023/09/12 14:45:49 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>

/*helper functions*/
int	ft_putchar(unsigned int c);
int	ft_putstr(char *s);

/*parse numbers*/
int	ft_putnbr(long n);
int	ft_putunsign(unsigned int n);
int	ft_puthex(unsigned long long int n, char c);
int	ft_putpointer(unsigned long long n);

/* printf function */
int	ft_parseformat(char f, va_list args);
int	ft_printf(const char *str, ...);

#endif
