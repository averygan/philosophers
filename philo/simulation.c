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

/* Checks if simulation has ended */
int	end_checker(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->end_mutex);
	if (philo->data->sim_end == 1)
		return (pthread_mutex_unlock(&philo->data->end_mutex), 1);
	pthread_mutex_unlock(&philo->data->end_mutex);
	return (0);
}

/* Eat function
- Locks forks and meal mutexes, when both forks locked, being eating
- Set timestamp of last meal
- Unlock both forks */
void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_one);
	print(philo, "has taken a fork", 0);
	if (philo->data->num_philo == 1)
	{
		pthread_mutex_unlock(philo->fork_one);
		return ;
	}
	pthread_mutex_lock(philo->fork_two);
	print(philo, "has taken a fork", 0);
	pthread_mutex_lock(&philo->eat_mutex);
	philo->eating = 1;
	philo->last_meal = timestamp();
	print(philo, "is eating", 0);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->eat_mutex);
	ft_usleep(philo->data->tte);
	philo->eating = 0;
	pthread_mutex_unlock(philo->fork_one);
	pthread_mutex_unlock(philo->fork_two);
}

/* Print and usleep */
void	ft_sleep(t_philo *philo)
{
	print(philo, "is sleeping", 0);
	ft_usleep(philo->data->tts);
}

/* Starts simulation 
- Loops through eat, think, sleep */
void	*simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if ((philo->id + 1) % 2 == 0)
		ft_usleep(1);
	while (!end_checker(philo) && ((philo->meals_eaten < philo->data->num_meals \
		&& philo->data->num_meals > -1) || philo->data->num_meals == -1))
	{
		eat(philo);
		if (philo->data->num_philo > 1)
		{
			ft_sleep(philo);
			print(philo, "is thinking", 0);
		}
		if (philo->id % 2)
			ft_usleep(1);
		if (philo->data->num_philo == 1)
			break ;
	}
	return (NULL);
}

/* Creates philo threads and monitor thread */
int	threads_init(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
		if (pthread_create(&data->philo[i].thread, NULL, \
			simulation, &data->philo[i]))
			return (print_err(PTHREAD_ERR), 0);
	if (pthread_create(&data->monitoring, NULL, ft_monitor, data))
		return (print_err(PTHREAD_ERR), 0);
	return (1);
}
