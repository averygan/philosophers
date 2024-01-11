/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:11:34 by agan              #+#    #+#             */
/*   Updated: 2024/01/08 15:11:55 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

// Clean up function to free all memory
void ft_free(t_data *data)
{
	int i;

	i = -1;
	pthread_mutex_destroy(&data->end_mutex);
	pthread_mutex_destroy(&data->print);
	while (++i < data->num_philo)
	{
		pthread_mutex_destroy(&data->philo[i].eat_mutex);
		pthread_mutex_destroy(data->philo[i].fork_one);
		pthread_mutex_destroy(data->philo[i].fork_two);
		pthread_mutex_destroy(&data->forks[i]);
	}
	if (data->philo)
		free(data->philo);
	if (data->forks)
		free(data->forks);
}

// Returns timestamp in milliseconds
long int	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

// int ft_strcmp(char *s1, char *s2)
// {
// 	int i;

// 	i = 0;
// 	while (s1[i])
// 	{
// 		if (s1[i] != s2[i])
// 			return (s1[i] - s2[i]);
// 		i++;
// 	}
// 	return (s1[i] - s2[i]);
// }

// Prints message to stdout
void print(t_philo *philo, char *str, int dead)
{
    long int    time;

    pthread_mutex_lock(&philo->data->print);
    time = timestamp() - philo->data->start_time;
    if (philo->data->sim_end == 0 && dead == 0)
    	printf("%ld %i %s\n", time, philo->id + 1, str);
	else if (philo->data->sim_end == 1 && dead == 1)
    	printf("%ld %i %s\n", time, philo->id + 1, str);
    pthread_mutex_unlock(&philo->data->print);
}
