/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death_and_meal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:06:01 by nromito           #+#    #+#             */
/*   Updated: 2024/06/24 17:05:44 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	philo_died(t_philo *philo)
{
	pthread_mutex_lock(philo->eating);
	if (get_real_time() - philo->last_meal >= philo->time_to_die
			&& philo->is_eating == 0)
		return (pthread_mutex_unlock(philo->eating), 1);
	return (pthread_mutex_unlock(philo->eating), 0);
}

int	is_dead(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->n_philos)
	{
		if (philo_died(&philo[i]))
		{
			print_message("died", &philo[i], philo[i].id);
			pthread_mutex_lock(philo->death);
			philo->death_prove = 1;
			return (pthread_mutex_unlock(philo->death), 1);
		}
	}
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
	t_philo	*philo;

	philo = (t_philo *)pointer;
	while (1)
	{
		if (is_dead(philo) || everybody_ate(philo))
			break;
	}
	return (pointer);
}