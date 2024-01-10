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

// Monitoring thread
// - Are there dead philosophers?
// - Have they taken all meals?
void *ft_monitor(void *arg)
{
	int i;
	t_data *data;

	data = (t_data *)arg;
	while (!data->sim_end)
	{
		i = -1;
		while (++i < data->num_philo)
		{
			if (timestamp() - data->philo[i].last_meal >= data->ttd && \
				data->philo[i].meals_eaten != data->num_meals)
			{
				pthread_mutex_lock(&data->end_mutex);
				data->sim_end = 1;
				data->philo[i].dead = 1;
				print(&data->philo[i], "died");
				pthread_mutex_unlock(&data->end_mutex);
				break ;
			}
		}
	}
	return (NULL);
}
