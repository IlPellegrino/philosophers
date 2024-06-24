/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:54:28 by nromito           #+#    #+#             */
/*   Updated: 2024/06/24 17:12:19 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	times_init(t_philo *philo, char **argv)
{
	philo->start_time = get_real_time();
	philo->last_meal = get_real_time();
	philo->n_philos = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->n_times_to_eat = ft_atoi(argv[5]);
	else
		philo->n_times_to_eat = -1;
}

void	init_mutex(t_data *data)
{
	pthread_mutex_init(&data->death, NULL);
	pthread_mutex_init(&data->eating, NULL);
	pthread_mutex_init(&data->print, NULL);
}

void	init_philos(t_philo *philo, t_mutex *forks, char **argv, t_data *data)
{
	int	i;

	i = -1;
	init_mutex(data);
	while (++i < ft_atoi(argv[1]))
	{
		times_init(&philo[i], argv);
		philo[i].id = i + 1;
		philo[i].meals_eaten = 0;
		philo[i].is_eating = 0;
		philo[i].death_prove = 0;
		philo[i].death = &data->death;
		philo[i].print = &data->print;
		philo[i].eating = &data->eating;
		philo[i].sx_fork = forks[i];
		if (i == 0)
			philo[i].dx_fork = forks[philo[i].n_philos - 1];
		else
			philo[i].dx_fork = forks[i - 1];
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
