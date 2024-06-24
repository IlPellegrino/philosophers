/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:21:05 by nromito           #+#    #+#             */
/*   Updated: 2024/06/24 17:03:15 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->dx_fork);
	print_message("has taken a fork", philo, philo->id);
	if (philo->n_philos == 1)
	{
		usleep(philo->time_to_die * 1000);
		pthread_mutex_unlock(&philo->dx_fork);
		return ;
	}
	pthread_mutex_lock(&philo->sx_fork);
	print_message("has taken a fork", philo, philo->id);
	philo->is_eating = 1;
	pthread_mutex_lock(philo->eating);
	print_message("is eating", philo, philo->id);
	philo->last_meal = get_real_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->eating);
	usleep(philo->time_to_eat * 1000);
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->sx_fork);
	pthread_mutex_unlock(&philo->dx_fork);
}

void	dream(t_philo *philo)
{
	print_message("is sleeping", philo, philo->id);
	usleep(philo->time_to_sleep * 1000);
}

void	think(t_philo *philo)
{
	print_message("is thinking", philo, philo->id);
}