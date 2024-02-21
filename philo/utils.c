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

/* Clean up function to free all memory */
void	ft_free(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&data->end_mutex);
	pthread_mutex_destroy(&data->print);
	while (++i < data->num_philo)
	{
		pthread_mutex_destroy(&data->philo[i].eat_mutex);
		pthread_mutex_destroy(&data->forks[i]);
	}
	if (data->philo)
		free(data->philo);
	if (data->forks)
		free(data->forks);
}

int	ft_usleep(long int milliseconds)
{
	long int	start;

	start = timestamp();
	while ((timestamp() - start) < milliseconds)
		usleep(500);
	return (0);
}

/* Returns timestamp in milliseconds */
long int	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

/* Locks and unlock print mutex - prints message to stdout */
void	print(t_philo *philo, char *str, int dead)
{
	long int	time;

	pthread_mutex_lock(&philo->data->print);
	time = timestamp() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->end_mutex);
	if (philo->data->sim_end == 0 && dead == 0)
		printf("%ld %i %s\n", time, philo->id + 1, str);
	else if (philo->data->sim_end == 1 && dead == 1)
		printf("%ld %i %s\n", time, philo->id + 1, str);
	pthread_mutex_unlock(&philo->data->end_mutex);
	pthread_mutex_unlock(&philo->data->print);
}

void	print_err(int err)
{
	if (err == ARG_ERR)
		printf("error: ./philo [NO. PHILOS] [TTD] [TTE] [TTS] [NO. MEALS]\n");
	else if (err == NUM_ERR)
		printf("error: philo takes positive, numeric arguments only\n");
	else if (err == PTHREAD_ERR)
		printf("philo: error creating thread\n");
	else if (err == MUTEX_ERR)
		printf("philo: error creating mutex\n");
	else if (err == MEM_ERR)
		printf("philo: error allocating memory\n");
}
