/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death_and_meal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:06:01 by nromito           #+#    #+#             */
/*   Updated: 2024/06/20 18:39:29 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	is_not_dead(t_philo *philo)
{
	if (philo->data->time_to_die < (philo->data->time_to_eat + philo->data->time_to_sleep))
	{
		pthread_mutex_lock(philo->death);
		philo->data->death = 1;
		print_message("is dead", philo, philo->id);
		pthread_mutex_unlock(philo->death);
		return (0);
	}
	philo->data->death = 0;
	return (1);
}

int	everybody_ate(t_philo *philo)
{
	int	i;

	i = -1;
	if (philo->meals_eaten == -1)
		return (1);
	return (0);
}

void	*monitor(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	while (1)
		if (everybody_ate(philo) || !is_not_dead(philo))
		{
			return (pointer);
		}
	return (pointer);
}