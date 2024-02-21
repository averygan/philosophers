/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:22:34 by agan              #+#    #+#             */
/*   Updated: 2024/01/10 15:22:34 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

/* Function to check if philo died from not eaing */
int	death_check(t_philo *philo, long ttd)
{
	pthread_mutex_lock(&philo->eat_mutex);
	if (timestamp() - philo->last_meal >= ttd && philo->eating == 0)
		return (pthread_mutex_unlock(&philo->eat_mutex), 1);
	pthread_mutex_unlock(&philo->eat_mutex);
	return (0);
}

/* Monitoring thread
- Checks for 1) If philos are dead, sim ends
			 2) If all philos are full, sim ends */
void	*ft_monitor(void *arg)
{
	int		i;
	int		meals_flag;
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		i = -1;
		meals_flag = 0;
		while (++i < data->num_philo)
		{
			if (death_check(&data->philo[i], data->ttd))
			{
				pthread_mutex_lock(&data->end_mutex);
				data->sim_end = 1;
				data->philo[i].dead = 1;
				pthread_mutex_unlock(&data->end_mutex);
				print(&data->philo[i], "died", 1);
				return (NULL);
			}
		}
		i = -1;
		while (++i < data->num_philo)
		{
			pthread_mutex_lock(&data->philo[i].eat_mutex);
			if ((data->philo[i].meals_eaten < data->num_meals && data->num_meals > -1) \
				|| data->num_meals == -1)
				meals_flag = 1;
			pthread_mutex_unlock(&data->philo[i].eat_mutex);
		}
		if (meals_flag == 0)
		{
			pthread_mutex_lock(&data->end_mutex);
			data->sim_end = 1;
			pthread_mutex_unlock(&data->end_mutex);
			break ;
		}
	}
	return (NULL);
}
