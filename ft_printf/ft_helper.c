/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:48:54 by agan              #+#    #+#             */
/*   Updated: 2023/09/12 17:49:08 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*Helper functions for output*/
int	ft_putchar(unsigned int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		count += 6;
		return (count);
	}
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
		count++;
	}
	return (count);
}
