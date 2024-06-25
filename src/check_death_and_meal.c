/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death_and_meal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:06:01 by nromito           #+#    #+#             */
/*   Updated: 2024/06/25 16:39:24 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	philo_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->eating);
	if (get_real_time() - philo->last_meal >= philo->data->time_to_die
			&& philo->is_eating == 0)
		return (pthread_mutex_unlock(&philo->eating), 1);
	return (pthread_mutex_unlock(&philo->eating), 0);
}

int	is_dead(t_philo *philos[MAX_PHILO])
{
	int	i;
	t_data *data;

	data = philos[0]->data;
	i = -1;
	while (++i < data->n_philos)
	{
		if (philo_died(philos[i]))
		{
			print_message("died", philos[i], philos[i]->id);
			pthread_mutex_lock(&data->death);
			data->death_prove = 1;
			pthread_mutex_unlock(&data->death);
			return (1);
		}
	}
	// pthread_mutex_unlock(philo->data->death);
	return (0);
}

int	everybody_ate(t_philo *philo)
{
	int	i;

	i = -1;
	if (philo->meals_eaten == -1)
		return (0);
	
	return (0);
}

void	*monitor(void *pointer)
{
	while (1)
	{
		// usleep(philo[0].time_to_die);
		if (is_dead(pointer) || everybody_ate(pointer))
			break;
	}
	return (pointer);
}