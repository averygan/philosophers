/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:10:13 by agan              #+#    #+#             */
/*   Updated: 2024/01/03 15:10:14 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	res;
	int	i;
	int	sign;

	res = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) && nptr[i])
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

// Checks for negative values or non valid integers
bool arg_checker(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '+')
			j++;
		else if (argv[i][0] == '-')
			return (0);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int var_init(int argc, char **argv)
{
	if (!arg_checker(argc, argv))
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	//t_info data;

	if (argc != 5 && argc != 6)
		return (0);
	else
	{
		printf("%d\n", var_init(argc, argv));
		return (1);
	}
}
