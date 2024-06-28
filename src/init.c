/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:54:28 by nromito           #+#    #+#             */
/*   Updated: 2024/06/28 10:44:53 by nromito          ###   ########.fr       */
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
	pthread_mutex_init(&data->death, NULL);
	if (pthread_mutex_init(&data->print, NULL) != 0)
	{
		write(2, "Failed to create mutex\n", 24);
		return ;
	}
	data->philos = ft_calloc(data->n_philos, sizeof(t_philo));
	if (!data->philos)
	{
		write(2, "Structure allocation failed\n", 29);
		return ;
	}
}

void	init_philos(char **argv, t_data *data)
{
	int	i;
	int	n_philos;

	i = -1;
	n_philos = ft_atoi(argv[1]);
	while (++i < n_philos)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal = get_real_time();
		init_mutex(&data->philos[i]);
		if (i == 0)
		{
			data->philos[i].dx_fork = &data->forks[n_philos - 1];
			data->philos[i].sx_fork = &data->forks[i];
		}
		else
		{
			data->philos[i].dx_fork = &data->forks[i - 1];
			data->philos[i].sx_fork = &data->forks[i];
		}
	}
	data->start_time = get_real_time();
}

int	init_forks(t_data *data)
{
	int	i;

	i = -1;
	data->forks = malloc(data->n_philos * sizeof(t_mutex));
	while (++i < data->n_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (write (2, "Mutex creation failed\n", 23), 0);
	}
	return (1);
}
