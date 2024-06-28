/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death_and_meal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:06:01 by nromito           #+#    #+#             */
/*   Updated: 2024/06/28 10:43:43 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	philo_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->eating);
	if (get_real_time() - philo->last_meal >= philo->data->time_to_die)
		return (pthread_mutex_unlock(&philo->eating), 1);
	return (pthread_mutex_unlock(&philo->eating), 0);
}

int	is_dead(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
	{
		if (philo_died(&data->philos[i]))
		{
			pthread_mutex_lock(&data->death);
			data->death_prove = 1;
			pthread_mutex_unlock(&data->death);
			print_message("died", &data->philos[i], data->philos[i].id);
			return (1);
		}
	}
	return (0);
}

int	everybody_ate(t_data *data)
{
	int	i;
	int	philos_full;

	i = -1;
	philos_full = 0;
	if (data->n_times_to_eat == -1)
		return (0);
	while (++i < data->n_philos)
	{
		pthread_mutex_lock(&data->philos[i].eating);
		if (data->philos[i].meals_eaten >= data->n_times_to_eat)
			philos_full++;
		pthread_mutex_unlock(&data->philos[i].eating);
	}
	if (philos_full == data->n_philos)
	{
		pthread_mutex_lock(&data->death);
		data->death_prove = 1;
		pthread_mutex_unlock(&data->death);
		return (1);
	}
	return (0);
}

void	*monitor(void *pointer)
{
	t_data	*data;

	data = (t_data *)pointer;
	while (1)
	{
		if (is_dead(data) || everybody_ate(data))
			break ;
	}
	return (data);
}
