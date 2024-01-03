/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:13:49 by agan              #+#    #+#             */
/*   Updated: 2024/01/03 16:08:54 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include "../ft_printf/ft_printf.h"
#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_info
{
	int num_philo;
	long ttd;
	long tte;
	long tts;
	long num_meals;
}	t_info;

#endif
