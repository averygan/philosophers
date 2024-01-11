/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:27:16 by agan              #+#    #+#             */
/*   Updated: 2024/01/08 13:27:17 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

// Function to assign two forks to a philosopher
void assign_forks(t_data *data)
{
	int i;
	int id;

	i = -1;
	id = 0;
	while (++i < data->num_philo)
	{
		id = data->philo[i].id;
		if (id + 1 != data->num_philo)
		{
			data->philo[i].fork_one = &data->forks[id];
			data->philo[i].fork_two = &data->forks[id + 1];
		}
		else
		{
			data->philo[i].fork_one = &data->forks[0];
			data->philo[i].fork_two = &data->forks[id];
		}
	}
}

// Function to loop through n philosophers and create n forks
void create_forks(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->num_philo)
	{
		pthread_mutex_init(&(data->philo[i].eat_mutex), NULL);
		pthread_mutex_init(&data->forks[i], NULL);
	}
}

// Initializes philosopher variables
int philo_init(t_data *data)
{
	int i;

	i = -1;
	data->philo = malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philo)
		return (0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->forks)
		return (0);
	create_forks(data);
	while (++i < data->num_philo)
	{
		data->philo[i].id = i;
		data->philo[i].dead = 0;
		data->philo[i].data = data;
		data->philo[i].eating = 0;
		data->philo[i].meals_eaten = 0;
		data->philo[i].last_meal = data->start_time;
	}
	assign_forks(data);
	return (1);
}
