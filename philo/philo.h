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

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>

# define NUM_PHILO 1
# define TTD 2
# define TTE 3
# define TTS 4
# define NUM_MEALS 5

enum e_philo_err
{
	NO_ERR,
	ARG_ERR,
	NUM_ERR,
	PTHREAD_ERR,
	MUTEX_ERR,
	MEM_ERR,
};

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		thread;
	int				id;
	int				meals_eaten;
	int				dead;
	int				eating;
	long int		last_meal;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	*fork_one;
	pthread_mutex_t	*fork_two;
}	t_philo;

typedef struct s_data
{
	int				sim_end;
	long			num_philo;
	long			ttd;
	long			tte;
	long			tts;
	long			num_meals;
	int				dead;
	t_philo			*philo;
	long int		start_time;
	pthread_t		monitoring;
	pthread_mutex_t	end_mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}	t_data;

// Philo functions
void		*ft_monitor(void *arg);
void		*simulation(void *data);
int			threads_init(t_data *data);

int			var_init(int argc, char **argv, t_data *data);
int			philo_init(t_data *data);

// Utils functions
void		print(t_philo *philo, char *str, int dead);
long int	timestamp(void);
int			ft_usleep(long int milliseconds);
void		ft_free(t_data *data);
void		print_err(int err);

#endif
