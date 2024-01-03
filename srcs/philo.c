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
	t_data data;

	if (argc != 5 && argc != 6)
		return (0);
	else
	{
		if (var_init(argc, argv, &data))
			return (1);
		// printf("num_philo %ld\n", data.num_philo);
		// printf("ttd %ld\n", data.ttd);
		// printf("tte %ld\n", data.tte);
		// printf("tts %ld\n", data.tts);
		// printf("num_meals %ld\n", data.num_meals);
	}
}
