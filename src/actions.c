/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromito <nromito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:21:05 by nromito           #+#    #+#             */
/*   Updated: 2024/06/20 10:22:19 by nromito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->dx_fork);
	print_message("has taken a fork", philo, philo->id);
	if (philo->data->n_philos == 1)
	{
		usleep(philo->data->time_to_die);
		pthread_mutex_unlock(philo->dx_fork);
		return ;
	}
	pthread_mutex_lock(philo->sx_fork);
	print_message("has taken a fork", philo, philo->id);
	pthread_mutex_lock(philo->eating);
	print_message("is eating", philo, philo->id);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->eating);
	// printf("philos number = %p\n", philo);
	// printf("philos number = %p\n", philo->data);
	usleep(philo->data->time_to_eat * 1000);
	// printf("philos number = %lld\n", philo->data->time_to_eat);
	pthread_mutex_unlock(philo->sx_fork);
	pthread_mutex_unlock(philo->dx_fork);
}

void	dream(t_philo *philo)
{
	print_message("is sleeping", philo, philo->id);
	usleep(philo->data->time_to_sleep * 1000);
}

void	think(t_philo *philo)
{
	print_message("is thinking", philo, philo->id);
}