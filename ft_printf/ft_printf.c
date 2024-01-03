/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:43:58 by agan              #+#    #+#             */
/*   Updated: 2023/09/12 14:43:59 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parseformat(char f, va_list args)
{
	int	count;

	count = 0;
	if (f == 'c')
		count += ft_putchar(va_arg(args, unsigned int));
	else if (f == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (f == 'd' || f == 'i')
		count += ft_putnbr((long)va_arg(args, int));
	else if (f == '%')
		count += ft_putchar('%');
	else if (f == 'u')
		count += ft_putunsign(va_arg(args, unsigned int));
	else if (f == 'x' || f == 'X')
		count += ft_puthex(va_arg(args, unsigned int), f);
	else if (f == 'p')
		count += ft_putpointer((unsigned long long)va_arg(args, void *));
	else
		count += ft_putchar(f);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			count += ft_parseformat(str[++i], args);
		else
			count += ft_putchar(*(str + i));
		i++;
	}
	return (count);
}

/*#include <limits.h>

int	main(void)
{
	int	digits;
	digits = 0;
	char *s;
	s = "string!";

	digits = ft_printf("ft_printf: This is a string %p\n", s);
	printf("Chars printed: %d\n", digits);
	digits = printf("og_printf: This is a string %p\n", s);
	printf("Chars printed: %d\n", digits);

	digits = ft_printf("ft_printf: numbers %i %d %i %i\n", \
	100, 50, INT_MAX, INT_MIN);
	printf("Chars printed: %d\n", digits);
	digits = printf("og_printf: numbers %i %d %i %i\n", \
	100, 50, INT_MAX, INT_MIN);
	printf("Chars printed: %d\n", digits);

	digits = ft_printf("ft_printf: numbers %d %d %d\n", -1, -9, -10);
	printf("Chars printed: %d\n", digits);
	digits = printf("og_printf: numbers %d %d %d\n", -1, -9, -10);
	printf("Chars printed: %d\n", digits);

	digits = ft_printf("ft_printf: numbers %x %x %x\n", 16, -200, INT_MAX);
	printf("Chars printed: %d\n", digits);
	digits = printf("og_printf: numbers %x %x %x\n", 16, -200, INT_MAX);
	printf("Chars printed: %d\n", digits);

	digits = ft_printf("ft_printf: unsigned %i, hex %x, hex cap %X\n", \
	INT_MAX, INT_MIN, INT_MIN);
	printf("Chars printed: %d\n", digits);
	digits = printf("og_printf: unsigned %i, hex %x, hex cap %X\n", \
	INT_MAX, INT_MIN, INT_MIN);
	printf("Chars printed: %d\n", digits);
}*/
