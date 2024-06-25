/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:54:28 by nromito           #+#    #+#             */
/*   Updated: 2024/06/25 16:26:35 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	times_init(t_data *data, char **argv)
{
	data->n_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->n_times_to_eat = ft_atoi(argv[5]);
	else
		data->n_times_to_eat = -1;
}

void	init_mutex(t_philo *philo)
{
	if (pthread_mutex_init(&philo->eating, NULL) != 0)
	{
		write(2, "Failed to create mutex\n", 24);
		return ;
	}
}

void	init_data(t_data *data, char **argv)
{
	times_init(data, argv);
	data->death_prove = 0;
	if (pthread_mutex_init(&data->death, NULL) != 0
		|| pthread_mutex_init(&data->print, NULL) != 0)
	{
		write(2, "Failed to create mutex\n", 24);
		return ;
	}
}

void	init_philos(t_philo *philos[MAX_PHILO], t_mutex *forks, char **argv, t_data *data)
{
	int	i;
	int n_philos = ft_atoi(argv[1]);

	i = -1;
	init_data(data, argv);
	while (++i < n_philos)
	{
		philos[i] = (t_philo *)malloc(sizeof(t_philo));
		//TODO check malloc
		philos[i]->data = data;
		philos[i]->id = i + 1;
		philos[i]->meals_eaten = 0;
		philos[i]->is_eating = 0;
		philos[i]->last_meal = get_real_time();
		philos[i]->start_time = get_real_time();
		init_mutex(philos[i]);
		philos[i]->sx_fork = forks[i];
		if (i == 0)
			philos[i]->dx_fork = forks[n_philos - 1];
		else
			philos[i]->dx_fork = forks[i - 1];
	}
}

int	init_forks(t_mutex *forks, char **argv)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(argv[1]))
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (write (2, "Mutex creation failed\n", 23), 0);
	return (1);
}
