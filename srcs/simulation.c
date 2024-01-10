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

int end_checker(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->end_mutex);
    if (philo->data->sim_end == 1)
        return(pthread_mutex_unlock(&philo->data->end_mutex), 1);
    pthread_mutex_unlock(&philo->data->end_mutex);
    return (0);
}

void eat(t_philo *philo)
{
    if (!philo->data->sim_end)
    {
        pthread_mutex_lock(philo->fork_one);
        print(philo, "has taken a fork");
        pthread_mutex_lock(philo->fork_two);
        print(philo, "has taken a fork");
        print(philo, "is eating");
        pthread_mutex_lock(&philo->eat_mutex);
        usleep(philo->data->tte * 1000);
        philo->meals_eaten++;
        philo->last_meal = timestamp();
        pthread_mutex_unlock(philo->fork_one);
        pthread_mutex_unlock(philo->fork_two);
        pthread_mutex_unlock(&philo->eat_mutex);
    }
}

void ft_sleep(t_philo *philo)
{
    print(philo, "is sleeping");
    usleep(philo->data->tts * 1000);
}

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
        print(philo, "is thinking");
	}
	return (NULL);
}

// void *simulation(void *data)
// {
// 	t_philo *philo;

// 	philo = (t_philo *)data;
//     if (philo->id % 2 == 0)
// 		usleep(100);
// 	while (!end_checker(philo))
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