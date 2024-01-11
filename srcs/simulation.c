/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:29:29 by agan              #+#    #+#             */
/*   Updated: 2024/01/10 13:29:35 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

// Checks if simulation has ended
int end_checker(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->end_mutex);
    if (philo->data->sim_end == 1)
        return(pthread_mutex_unlock(&philo->data->end_mutex), 1);
    pthread_mutex_unlock(&philo->data->end_mutex);
    return (0);
}

// Eat function
// Locks forks and meal mutexes - when both forks are locked, begin eating
// Set timestamp of last meal
// Unlock both forks
void eat(t_philo *philo)
{
    pthread_mutex_lock(philo->fork_one);
    print(philo, "has taken a fork", 0);
    pthread_mutex_lock(philo->fork_two);
    print(philo, "has taken a fork", 0);
    philo->eating = 1;
    print(philo, "is eating", 0);
    pthread_mutex_lock(&philo->eat_mutex);
    pthread_mutex_unlock(&philo->eat_mutex);
    philo->meals_eaten++;
    philo->last_meal = timestamp();
    ft_usleep(philo->data->tte * 1000);
    philo->eating = 0;
    pthread_mutex_unlock(philo->fork_one);
    pthread_mutex_unlock(philo->fork_two);
}

// Sleep function -> print and usleep
void ft_sleep(t_philo *philo)
{
    print(philo, "is sleeping", 0);
    ft_usleep(philo->data->tts * 1000);
}

// Start simulation -> loops through eat, sleep, think
void *simulation(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
    if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!end_checker(philo) && philo->meals_eaten < philo->data->num_meals)
	{
		eat(philo);
        ft_sleep(philo);
        print(philo, "is thinking", 0);
	}
	return (NULL);
}

// Creates philosopher threads
void threads_init(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->num_philo)
		pthread_create(&data->philo[i].thread, NULL, simulation, &data->philo[i]);
	pthread_create(&data->monitoring, NULL, ft_monitor, data);
}
