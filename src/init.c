/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:54:28 by nromito           #+#    #+#             */
/*   Updated: 2024/06/18 16:58:55 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	init_philos(t_philo *philo, t_data *data, t_mutex *forks)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
	{
		philo[i].id = i + 1;
		philo[i].times_eaten = 0;
		philo->data->n_philos = data->n_philos;
		philo->data->time_to_sleep = data->time_to_sleep;
		philo->data->time_to_die = data->time_to_die;
		philo->data->time_to_eat = data->time_to_eat;
		philo[i].sx_fork = &forks[i];
		if (i == 0)
			philo[i].dx_fork = &forks[data->n_philos - 1];
		else
			philo[i].dx_fork = &forks[i - 1];
	}
}

int	init_forks(t_philo *philo, t_mutex *forks)
{
	int	i;

	i = -1;
	while (i < philo->data->n_philos)
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (write (2, "Mutex creation failed\n", 23), 0);
	return (1);
}

void	init_program(t_philo *philo, t_data *data, char **argv)
{
	data->philo = philo;
	data->death = 0;
	data->start_time = get_real_time(data);
	data->n_philos = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		data->n_times_to_eat = ft_atol(argv[5]);
	else
		data->n_times_to_eat = -1;
}