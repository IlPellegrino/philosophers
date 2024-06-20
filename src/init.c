/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:54:28 by nromito           #+#    #+#             */
/*   Updated: 2024/06/20 18:40:42 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	init_philos(t_philo *philo, t_data *data, t_mutex *forks)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
	{
		philo[i].data = data;
		philo[i].id = i + 1;
		philo[i].meals_eaten = 0;
		philo[i].death = &data->death_lock;
		philo[i].eating = &data->eating;
		philo[i].print = &data->print;
		philo[i].sx_fork = &forks[i];
		if (i == 0)
			philo[i].dx_fork = &forks[data->n_philos - 1];
		else
			philo[i].dx_fork = &forks[i - 1];
	}
}

int	init_forks(t_mutex *forks, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (write (2, "Mutex creation failed\n", 23), 0);
	return (1);
}

void	init_program(t_data *data, char **argv)
{
	data->death = 0;
	pthread_mutex_init(&data->death_lock, NULL);
	pthread_mutex_init(&data->eating, NULL);
	pthread_mutex_init(&data->print, NULL);
	data->n_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->n_times_to_eat = ft_atoi(argv[5]);
	else
		data->n_times_to_eat = -1;
}
