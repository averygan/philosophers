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

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = -1;
	if (argc != 5 && argc != 6)
		return (print_err(ARG_ERR), 1);
	if (var_init(argc, argv, &data))
		return (1);
	if (philo_init(&data))
		return (1);
	threads_init(&data);
	while (++i < data.num_philo)
		pthread_join(data.philo[i].thread, NULL);
	pthread_join(data.monitoring, NULL);
	ft_free(&data);
}
