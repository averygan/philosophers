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

// Simulation
// - Take fork_1
// - Take fork_2
// 	- Moves to thinking
// - Philosopher start with thinking
// 	- Time_to_think
// 	- Moves to sleeping
// - Sleeping
// 	- Time_to_sleep
// 	- Moves to thinking

// void philo_eat(t_philo *philo)
// {
// 	pthread_mutex_lock(philo->fork_one);
// 	print(philo, "has taken a fork");
// 	pthread_mutex_lock(philo->fork_two);
// 	print(philo, "has taken a fork");
// 	print(philo, "is eating");
// 	philo->eating = 1;
// 	pthread_mutex_lock(&philo->eat_mutex);
// 	usleep(philo->data->tte * 1000);
// 	philo->meals_eaten++;
// 	philo->last_meal = timestamp();
// 	pthread_mutex_unlock(philo->fork_one);
// 	pthread_mutex_unlock(philo->fork_two);
// 	pthread_mutex_unlock(&philo->eat_mutex);
// 	philo->eating = 0;
// 	philo->sleeping = 1;
// }

// void *simulation(void *data)
// {
// 	t_philo *philo;

// 	philo = (t_philo *)data;
// 	while (!philo->data->sim_end && philo->meals_eaten < philo->data->num_meals)
// 	{
// 		if (!philo->data->sim_end && !philo->thinking && !philo->sleeping)
// 			philo_eat(philo);
// 		else if (!philo->data->sim_end && philo->sleeping == 1)
// 		{
// 			print(philo, "is sleeping");
// 			usleep(philo->data->tts * 1000);
// 			philo->sleeping = 0;
// 			philo->thinking = 1;
// 		}
// 		if (!philo->data->sim_end && philo->thinking == 1)
// 		{
// 			print(philo, "is thinking");
// 			philo->thinking = 0;
// 		}
// 	}
// 	return (NULL);
// }

int	main(int argc, char **argv)
{
	t_data data;
	int i;

	i = -1;
	if (argc != 5 && argc != 6)
		return (0);
	else
	{
		if (var_init(argc, argv, &data))
			return (1);
		if (!philo_init(&data))
			return (1);
		while (++i < data.num_philo)
			pthread_join(data.philo[i].thread, NULL);
	}
}
