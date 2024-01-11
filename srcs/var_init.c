/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:33:25 by agan              #+#    #+#             */
/*   Updated: 2024/01/03 19:33:25 by agan             ###   ########.fr       */
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

// Initializes variables for data
int var_init(int argc, char **argv, t_data *data)
{
	if (!arg_checker(argc, argv))
		return (-1);
	data->sim_end = 0;
	data->num_philo = ft_atoi(argv[NUM_PHILO]);
	data->ttd = ft_atoi(argv[TTD]);
	data->tte = ft_atoi(argv[TTE]);
	data->tts = ft_atoi(argv[TTS]);
	if (argc == 6)
		data->num_meals = ft_atoi(argv[NUM_MEALS]);
	else
		data->num_meals = 0;
	data->start_time = timestamp();
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->end_mutex, NULL);
	return (0);
}
